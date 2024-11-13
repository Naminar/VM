from jinja2 import Environment, FileSystemLoader
from typing import List
import json


def read_isa_json_data(filepath: str) -> List:
    with open(filepath, 'r', encoding='utf-8') as f:
        return json.load(f)


def prepare_cpp_code(data: List) -> None:
    for instr in data:
        instr["len"] = 1
        instr["decode"] = ""
        instr["constructor"] = ""
        instr["constructor_args"] = []
        instr["create_args"] = []
        instr["args_cpp"] = []
        for i, arg in enumerate(instr["args"]):
            if arg["type"] == "RegType":
                instr["constructor_args"].append(f"RegType arg{i}")
                instr["create_args"].append(f"uint8_t arg{i}")
                instr["args_cpp"].append(f"RegType _arg{i}")
                instr["decode"] = f"_arg{i} = reinterpret_cast<uint8_t *>(ptr);\nptr += 1;\n"
                instr["len"] += 1
            elif arg["type"] == "LongType":
                instr["create_args"].append(f"int64_t arg{i}")
                instr["constructor_args"].append(f"LongType arg{i}")
                instr["args_cpp"].append(f"LongType _arg{i}")
                instr["decode"] = f"_arg{i} = reinterpret_cast<uint64_t *>(ptr);\nptr += 8;\n"
                instr["len"] += 8
            else:
                raise RuntimeError("Unreachable")

        instr["logic"] = instr["logic"].replace("_rv", '_return_value')
        instr["create_args"] += ["uint8_t *ptr, uint64_t size"]


def gen_isa_inc(data: List, file: str) -> None:
    template = env.get_template(f"{file}.j2")
    output = template.render({"instructions": data})
    with open(file, 'w') as f:
        f.write(output)


if __name__ == "__main__":
    isa_data = read_isa_json_data("./json/isa.json")
    prepare_cpp_code(isa_data)
    file_loader = FileSystemLoader('.')
    env = Environment(loader=file_loader)

    gen_isa_inc(isa_data, "isa_decl.inc")
    gen_isa_inc(isa_data, "isa_impl.inc")
    gen_isa_inc(isa_data, "init_func_vec.inc")