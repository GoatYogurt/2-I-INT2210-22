#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Student {
    int id;
    string name;
    string cls;
public:
    Student(int id_, string name_, string cls_) {
        id = id_;
        name = name_;
        cls = cls_;
    }

    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    string getClass() {
        return cls;
    }
};

class StudentManagement {
    map<int, Student*> students;
public:
    void Insert(int id_, string name_, string cls_) {
        Student* s = new Student(id_, name_, cls_);
        students.insert(pair<int, Student*>(id_, s));
    }

    void Delete(int id_){
        students.erase(id_);
    }
    void Infor(int id_) {
        string res;
        if (students[id_] == NULL) {
            cout << "NA,NA" << endl;
        } else {
            cout << students[id_]->getName() << "," << students[id_]->getClass() << endl;
        }
    }
};

int main() {
    StudentManagement uet;
    uet.Insert(1, "Tuan", "K61CS");
    uet.Insert(2, "Vinh", "K43C");
    uet.Infor(3);
    uet.Infor(2);
    uet.Delete(2);
    uet.Infor(2);
}

