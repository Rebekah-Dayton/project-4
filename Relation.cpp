//
// Created by Rebek on 11/1/2022.
//

#include "Relation.h"

Relation::Relation(std::string name, Header header){
    this->name = name;
    attributes = header;
}

void Relation::AddTuple(Tuple to_add) {
    tuples.insert(to_add);
}

std::string Relation::To_String() {
    std::string results = "  ";
    for (Tuple t : tuples) {
        for (int i = 0; i < attributes.GetSize(); i++) {
            results += attributes.GetAttribute(i) + "=" + t.GetValue(i);
            if (i != attributes.GetSize() - 1) {
                results += ", ";
            }
            if (i == attributes.GetSize() - 1) {
                results += "\n  ";
            }
        }
    }
    results.pop_back();
    results.pop_back();
    return results;
}

Relation::Relation() {

}

Relation *Relation::Select(int index, std::string selector) {
    Relation* select = new Relation(name, attributes);

    for (Tuple t : tuples) {
        if (t.GetValue(index) == selector) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::SelectTwo(int index1, int index2) {
    Relation* select = new Relation(name, attributes);

    for (Tuple t : tuples) {
        if (t.GetValue(index1) == t.GetValue(index2)) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::Project(std::vector<unsigned int> indices) {
    Relation *project = new Relation();
    project->SetName(name);
    Header header;
    for (unsigned int i = 0; i < indices.size(); i++) {
        header.AddAttribute(attributes.GetAttribute(indices.at(i)));
    }
    project->SetHeader(header);
    for (Tuple t: tuples) {
        Tuple newTuple;
        for (unsigned int i = 0; i < indices.size(); i++) {
            newTuple.AddValue(t.GetValue(indices.at(i)));
        }
        project->AddTuple(newTuple);
    }

    return project;
}

Relation *Relation::Rename(int index, std::string newAttribute) {
    Relation* rename = new Relation();
    rename->SetName(name);
    Header header;
    for (int i = 0; i < attributes.GetSize(); i++) {
        if (i == index) {
            header.AddAttribute(newAttribute);
        }
        else {
            header.AddAttribute((attributes.GetAttribute(i)));
        }
    }
    rename->SetHeader(header);

    for (Tuple t : tuples) {
        rename->AddTuple(t);
    }
    return rename;
}

Relation *Relation::NaturalJoin(Relation *to_join) {
    Header newHeader = attributes;
    Header joinHeader = to_join->GetHeader();
    for (int i = 0; i < to_join->GetHeaderSize(); i++) {
        int headerIndex = newHeader.FindAttribute(joinHeader.GetAttribute(i));
        if (headerIndex != -1) {
            matching.push_back(headerIndex);
            matching.push_back(i);
        }
        else {
            newHeader.AddAttribute(joinHeader.GetAttribute(i));
        }
    }

    Relation* naturalJoin = new Relation(name, newHeader);

    for (Tuple t1: tuples) {
        for (Tuple t2: to_join->GetTuples()) {
            if (CanJoin(t1, t2)) {
                Tuple newTuple = JoinTuples(t1, t2);
                naturalJoin->AddTuple(newTuple);

            }
        }
    }
    return naturalJoin;
}

void Relation::Union(Relation *relation) {
    addedTuple = false;
    Relation relation1(name, attributes);
    for (Tuple t : relation->GetTuples()) {
        if (tuples.insert(t).second) {
            relation1.AddTuple(t);
            addedTuple = true;
        }
    }
    std::cout << relation1.To_String();
}

Tuple Relation::JoinTuples(Tuple tuple1, Tuple tuple2) {
    Tuple tuple;
    if (matching.empty()) {
        for (int i = 0; i < tuple1.GetSize(); i++) {
            tuple.AddValue(tuple1.GetValue(i));
        }
        for (int i = 0; i < tuple2.GetSize(); i++) {
            tuple.AddValue(tuple2.GetValue(i));
        }
    }
    else {
        for (int i = 0; i < tuple1.GetSize(); i++) {
            tuple.AddValue(tuple1.GetValue(i));
        }
        for (int i = 0; i < tuple2.GetSize(); i++) {
            bool match = false;
            for (unsigned int j = 1; j < matching.size(); j = j + 2) {
                if (matching.at(j) == i) {
                    match = true;
                }
            }
            if (!match) {
                tuple.AddValue(tuple2.GetValue(i));
            }
        }
    }
    return tuple;
}

bool Relation::CanJoin(Tuple tuple1, Tuple tuple2) {
    bool canJoin = true;
    for (unsigned int i = 0; i < matching.size(); i = i + 2) {
        if (tuple1.GetValue(matching.at(i)) != tuple2.GetValue(matching.at(i + 1))) {
            canJoin = false;
        }
    }
    return canJoin;
}

