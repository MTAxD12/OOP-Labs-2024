#include "clase_json.h"

JsonValue::~JsonValue() {};

void addIndentation(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i) {
        out << "    "; // Add 4 spaces for each level
    }
}

//NullValue

void NullValue::print(std::ostream& out, int level) const {
	out << "null";
};


//NumberValue
NumberValue::NumberValue(int num) {nr = num;};

void NumberValue::print(std::ostream& out, int level) const {
	out << nr;
};


//StringValue
StringValue::StringValue(const char* val) { 
	unsigned int count = 0;
	for (int i = 0; val[i]; i++) 
		count++;

	string = new char[count];
	for (unsigned int i = 0; i < count; i++)
		string[i] = val[i];

    string[count] = '\0';
};

void StringValue::print(std::ostream& out, int level) const {
	out << "\"" << string << "\"";
}


//BoolValue
BoolValue::BoolValue(bool cond) { val = cond; }

void BoolValue::print(std::ostream& out, int level) const {
	out << val;
};


//ArrayValues
void ArrayValue::add(JsonValue* value) {
    if (size >= 16) {
        std::cout << "Maximul este de 16 elemente in array\n";
        return;
    }
    elemente[size++] = value;
};

void ArrayValue::print(std::ostream& out, int level) const {
    out << "[\n";
    for (unsigned int i = 0; i < size; ++i) {
        addIndentation(out, level + 1);
        elemente[i]->print(out, level + 1); // Printează elementul cu un nivel de indentare mai mare
        if (i != size - 1)
            out << ", ";
        out << "\n";
    }
    addIndentation(out, level);
    out << "]";
}


//ObjectValue
void ObjectValue::add(const char* name, JsonValue* value) {
    if (size >= 16) {
        std::cerr << "Maximul este de 16 elemente in obiect." << std::endl;
        return;
    }
    perechi[size++] = std::make_pair(name, value);
};

void ObjectValue::print(std::ostream& out, int level) const {
    out << "{\n";
    for (unsigned int i = 0; i < size; i++) {
        addIndentation(out, level + 1);
        out << "\"" << perechi[i].first << "\": ";
        if (typeid(*(perechi[i].second)) == typeid(BoolValue)) {
            BoolValue* boolValue = dynamic_cast<BoolValue*>(perechi[i].second);
            if (boolValue != nullptr) {
                if (boolValue) out << "true";
                else out << "false";
            }
        }
        else {
            perechi[i].second->print(out, level + 1);
        }

        if (i != size - 1)
            out << ", ";
        out << "\n";
    }
    addIndentation(out, level);
    out << "}";
}

