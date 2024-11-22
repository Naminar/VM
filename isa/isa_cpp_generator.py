from jinja2 import Environment, FileSystemLoader
from typing import List, Dict
import json
import sys
import os


def read_json_data(filepath: str) -> List:
    with open(filepath, 'r', encoding='utf-8') as f:
        return json.load(f)


def prepare_cpp_code(data: List) -> None:
    for instr in data:
        instr["create_args"] = []
        instr["len_without_array"] = 1
        for i, arg in enumerate(instr["args"]):
            instr["len_without_array"] += 8
            
            if arg["type"] != "ArrayType":
                instr["create_args"].append(f"uint64_t arg{i} /* {arg['type']} */")
            else:
                instr["create_args"].append(f"const int64_t *arg{i} /* args_array */")

        instr["logic"] = instr["logic"].replace("_rv", '_return_value')
        instr["logic"] = instr["logic"].replace("_ip", '_ptr')
        instr["opcode_define_name"] = ("OPCODE_" + instr["mnemonic"]).upper()


def gen_isa_inc(data: List, file: str) -> None:
    template = env.get_template(f"{file}.j2")
    output = template.render({"instructions": data})
    with open(os.path.join(sys.argv[2], file), 'w') as f:
        f.write(output)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"Wrong arguments! Usage: {sys.argv[0]} <script_dir> <gen_dir> <template_1> [, <template_2> [, ...]]")
        sys.exit(-1)

    isa_data = read_json_data(os.path.join(sys.argv[1], "json/isa.json"))
    
    prepare_cpp_code(isa_data)
    
    file_loader = FileSystemLoader(sys.argv[1])
    env = Environment(loader=file_loader)

    for template in sys.argv[3:]:
        gen_isa_inc(isa_data, os.path.splitext(os.path.basename(template))[0])