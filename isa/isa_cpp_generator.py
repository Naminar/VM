from jinja2 import Environment, FileSystemLoader
from typing import List, Dict
import json
import sys
import os


def read_json_data(filepath: str) -> List:
    with open(filepath, 'r', encoding='utf-8') as f:
        return json.load(f)


def prepare_cpp_code(data: List) -> None:
    dispatch_table = {}
    dispatch_table["do"] = ["CatchDoNullPtr" for i in range(256)]
    dispatch_table["dump"] = ["CatchDumpNullPtr" for i in range(256)]
    for instr in data["instructions"]:
        instr["create_args"] = []
        instr["create_arg_names"] = []
        instr["len_in_int64"] = 1
        for i, arg in enumerate(instr["args"]):
            instr["len_in_int64"] += 1
            instr["create_args"].append(f"int64_t arg{i} /* {arg['type']} */")
            instr["create_arg_names"].append(f"arg{i} /* {arg['type']} */")

            if arg["type"] == "RegType":
                instr["logic"] = instr["logic"].replace(f"_arg{i}", f"i->_current_frame->_regs[_arg{i}]")

        instr["logic"] = instr["logic"].replace("_arg", 'instr_struct->_arg')
        instr["logic"] = instr["logic"].replace("_rv", 'i->_current_frame->_return_value')
        instr["logic"] = instr["logic"].replace("_ptr", 'i->_current_frame->_ptr')
        instr["logic"] = instr["logic"].replace("_rc", 'i->_return_code')
        instr["logic"] = instr["logic"].replace("CreateFrame", 'i->CreateFrame')
        instr["logic"] = instr["logic"].replace("CallFuncById", 'i->CallFuncById')
        instr["logic"] = instr["logic"].replace("ReturnPreviousFrame", 'i->ReturnPreviousFrame')
        instr["logic"] = instr["logic"].replace("_ip", 'ptr')
        instr["opcode_define_name"] = ("OPCODE_" + instr["mnemonic"]).upper()

        dispatch_table["do"][instr["opcodeDec"]] = f"do_{instr['mnemonic']}"
        dispatch_table["dump"][instr["opcodeDec"]] = f"dump_{instr['mnemonic']}"
    data["dispatch_table"] = dispatch_table


def gen_isa_inc(data: List, file: str) -> None:
    template = env.get_template(f"{file}.j2")
    output = template.render(data)
    with open(os.path.join(sys.argv[2], file), 'w') as f:
        f.write(output)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"Wrong arguments! Usage: {sys.argv[0]} <script_dir> <gen_dir> <template_1> [, <template_2> [, ...]]")
        sys.exit(-1)

    isa_data = read_json_data(os.path.join(sys.argv[1], "json/isa.json"))
    data = {"instructions": isa_data}
    prepare_cpp_code(data)

    file_loader = FileSystemLoader(sys.argv[1])
    env = Environment(loader=file_loader)

    for template in sys.argv[3:]:
        gen_isa_inc(data, os.path.splitext(os.path.basename(template))[0])