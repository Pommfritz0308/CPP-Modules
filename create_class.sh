#!/bin/bash

# Check if a class name argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <class_name>"
    exit 1
fi

# Get the class name from the command-line argument
CLASS_NAME=$1

# HPP (Header) file creation
echo -e "#ifndef ${CLASS_NAME^^}_HPP\n#define ${CLASS_NAME^^}_HPP\n\n" > ${CLASS_NAME}.hpp
echo -e "class ${CLASS_NAME}\n{\n\tpublic:\n\t\t${CLASS_NAME}();
\t\t${CLASS_NAME}(const ${CLASS_NAME} &old);
\t\t${CLASS_NAME}& operator=(const ${CLASS_NAME}& old);
\t\t~${CLASS_NAME}();\n\n\tprivate:\n\t\t\n};\n\n#endif" >> ${CLASS_NAME}.hpp

# CPP (Implementation) file creation
echo -e "#include \"${CLASS_NAME}.hpp\"\n\n${CLASS_NAME}::${CLASS_NAME}()\n{\n\n}\n\n${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME} &old)\n{\n\n}\n" > ${CLASS_NAME}.cpp
echo -e "${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& old)\n{\n\tif (this != &old)\n\t{\n\n\t}\n\treturn *this;\n}\n\n${CLASS_NAME}::~${CLASS_NAME}()\n{\n\n}" >> ${CLASS_NAME}.cpp
# Add template code for other member functions if needed

echo "Files created: ${CLASS_NAME}.hpp and ${CLASS_NAME}.cpp"

