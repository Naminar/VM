from jinja2 import Environment, FileSystemLoader
from typing import List
import json


def read_isa_json_data(filepath: str) -> List:
    with open(filepath, 'r', encoding='utf-8') as f:
        return json.load(f)


def prepare_cpp_code(data: List) -> None:
    for instr in data:
        for i, arg in enumerate(instr["args"]):
            if arg["type"] == "reg":
                instr["logic"] = instr["logic"].replace(f"_arg{i}", 'GetReg()')
            elif arg["type"] == "long":
                instr["logic"] = instr["logic"].replace(f"_arg{i}", 'GetLong()')
            else:
                raise RuntimeError("Unreachable")

        instr["logic"] = instr["logic"].replace("_ip", 'GetIP()')
        instr["logic"] = instr["logic"].replace("_rv", 'GetRetVal()')


def gen_isa_cpp(data: List) -> None:
    file_loader = FileSystemLoader('.')
    env = Environment(loader=file_loader)
    template = env.get_template('isa.cpp.j2')
    output = template.render({"instructions": data})
    with open('isa.cpp', 'w') as f:
        f.write(output)


if __name__ == "__main__":
    isa_data = read_isa_json_data("./json/isa.json")
    prepare_cpp_code(isa_data)
    gen_isa_cpp(isa_data)