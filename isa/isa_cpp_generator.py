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
        instr["args_cpp"] = []
        for i, arg in enumerate(instr["args"]):
            if arg["type"] == "RegType":
                instr["constructor_args"].append(f"RegType arg{i}")
                instr["args_cpp"].append(f"RegType _arg{i}")
                instr["decode"] = f"_arg{i} = reinterpret_cast<uint8_t *>(ptr);\nptr += 1;\n"
                instr["len"] += 1
                instr["logic"] = instr["logic"].replace(f"_arg{i}", f"REG_FILE[_arg{i}]")
            elif arg["type"] == "LongType":
                instr["constructor_args"].append(f"LongType arg{i}")
                instr["args_cpp"].append(f"LongType _arg{i}")
                instr["decode"] = f"_arg{i} = reinterpret_cast<uint64_t *>(ptr);\nptr += 8;\n"
                instr["len"] += 8
            else:
                raise RuntimeError("Unreachable")

        instr["logic"] = instr["logic"].replace("_ip", 'IP')
        instr["logic"] = instr["logic"].replace("_rv", 'RET_VAL')


def gen_isa_cpp(data: List) -> None:
    file_loader = FileSystemLoader('.')
    env = Environment(loader=file_loader)
    template = env.get_template('isa.cpp.j2')
    output = template.render({"instructions": data})
    with open('isa.cpp', 'w') as f:
        f.write(output)
    template = env.get_template('isa.h.j2')
    output = template.render({"instructions": data})
    with open('isa.h', 'w') as f:
        f.write(output)


if __name__ == "__main__":
    isa_data = read_isa_json_data("./json/isa.json")
    prepare_cpp_code(isa_data)
    gen_isa_cpp(isa_data)