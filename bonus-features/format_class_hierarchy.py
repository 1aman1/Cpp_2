# File: format_class_hierarchy.py

import re

def format_class_hierarchy(filename):
    with open(filename, 'r') as file:
        content = file.read()

        # Remove compiler-generated comments
        content = re.sub(r'/\*.*?\*/', '', content)

        # Remove unnecessary whitespace and newlines
        content = content.replace('\n', '').replace('\t', '')

        # Format class hierarchy using indentation
        indentation_level = 0
        formatted_content = ''
        for line in content.split(';'):
            if line.startswith('Class '):
                formatted_content += '\n' + '\t' * indentation_level + line.strip() + ';'
                indentation_level += 1
            elif line.startswith('Class'):
                formatted_content += '\n' + '\t' * indentation_level + line.strip() + ';'
            elif line.startswith('Vtable'):
                indentation_level -= 1
                formatted_content += '\n' + '\t' * indentation_level + line.strip() + ';'
            else:
                formatted_content += line.strip() + ';'

        return formatted_content

# Usage:
formatted_hierarchy = format_class_hierarchy('nm.cpp.002t.class')
print(formatted_hierarchy)