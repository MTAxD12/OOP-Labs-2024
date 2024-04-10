#include "clase_json.h"

JsonValue::~JsonValue() {};

//NullValue

void NullValue::print(std::ostream& out) const {
	out << "null";
};


//NumberValue
NumberValue::NumberValue(int num) {nr = num;};

void NumberValue::print(std::ostream& out) const {
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

void StringValue::print(std::ostream& out) const {
	out << "\"" << string << "\"";
}


//BoolValue
BoolValue::BoolValue(bool cond) { val = cond; }

void BoolValue::print(std::ostream& out) const {
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

void ArrayValue::print(std::ostream& out) const {
    out << "[";
    for (unsigned int i = 0; i < size; ++i) {
        elemente[i]->print(out);
        if (i != size - 1)
            out << ", ";
    }
    out << "]";
};


//ObjectValue
void ObjectValue::add(const char* name, JsonValue* value) {
    if (size >= 16) {
        std::cerr << "Maximul este de 16 elemente in obiect." << std::endl;
        return;
    }
    perechi[size++] = std::make_pair(name, value);
};

void ObjectValue::print(std::ostream& out) const {
    out << "{";
    for (unsigned int i = 0; i < size; i++) {
        out << "\"" << perechi[i].first << "\": ";
        if (typeid(perechi[i].second) == typeid(bool))
            if (perechi[i].second) out << "true";
            else out << "false";
        else
            perechi[i].second->print(out);
        if (i != size - 1)
            out << ", ";
    }
    out << "}";
};
/*
unsigned int countNodes(const JsonValue* value) {
    const ObjectValue* object = dynamic_cast<const ObjectValue*>(value);
    if (object) {
        unsigned int count = 1; // count for the object itself
        for (const auto& pair : object) {
            count += countNodes(pair.second.get());
        }
        return count;
    }

    const ArrayValue* array = dynamic_cast<const ArrayValue*>(value);
    if (array) {
        unsigned int count = 1; // count for the array itself
        for (const auto& element : array) {
            count += countNodes(element.get());
        }
        return count;
    }

    return 1; // for null, number, bool, and string
}
*/