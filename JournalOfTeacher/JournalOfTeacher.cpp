#include "File.h"


class Student {
    int id;
    string name;
    int* mark1 = nullptr;
    int* mark2 = nullptr;
    int* mark3 = nullptr;
    int* mark4 = nullptr;
    int resultMarks[4];
    int resultYear;
public:
    Student() {};
    void show() {
        cout << "ID: " << id << "\nName: " << name << endl;
    }
    void setMarks(int* mark1, int* mark2, int* mark3, int* mark4) {
        this->mark1 = mark1;
        this->mark2 = mark2;
        this->mark3 = mark3;
        this->mark4 = mark4;
    }

};

class Group {
    string name;
    Student* students = nullptr;
    int studentsCount = 0;
public:
    Group() {};
    Group(string name) {
        this->name = name;
    }
    void addStudent(Student st) {
        Student* buf = new Student[studentsCount + 1];
        for (int i = 0; i < studentsCount; i++) {
            buf[i] = students[i];
        }
        buf[studentsCount++] = st;

        delete[] students; // добавить Student диструктор
        students = buf;
    }
    string getName() {
        return name;
    }

};

class Journal {
    string subject;
    string teacherName;
    Group* groups = nullptr;
    int groupsCount = 0;
public:
    Journal(string subject, string teacherName){
        this->subject = subject;
        this->teacherName = teacherName;
    }

    void addGroup(Group gr) {
        Group* buf = new Group[groupsCount + 1];
        for (int i = 0; i < groupsCount; i++) {
            buf[i] = groups[i];
        }
        buf[groupsCount++] = gr;

        delete[] groups; // добавить Group диструктор
        groups = buf;
    }

    void addStudentInGroup(Student st) {

    }

    void info() {
        for (int i = 0; i < groupsCount; i++) {
            cout << groups[i].getName() << endl;
        }
    }
};


int fileCounter(string path) {
    ifstream in(path);
    if (in.is_open()) {
        int counter = 0;
        string str;
        while (getline(in, str)) {
            counter += 1;
        }
        return counter;
    }
    else return 0;


}

string* readFile(string path) {
    fstream in(path);
    if (in.is_open()) {
        int fileSize = fileCounter(path);
        string* array = new string[fileSize + 1];
        string str;
        int counter = 1;
        array[0] = to_string(fileSize);
        while (getline(in, str)) {
            array[counter++] = str;
        }
        return array;
    }
    else return nullptr;
}

void showArray(string* array) {
    int size = stoi(array[0]);
    for (int i = 1; i < size; i++) {
        cout << array[i] << endl;
    }
}


string* split(string str, char s) {
    string* data = new string[6];
    string curStr;
    int c = 0;
    for (int j = 0; j < 6; j++) {
        curStr = "";
        while (str[c] != '\n' && str[c] != s && str[c] != '\0') {
            curStr += str[c++];
        }
        data[j] = curStr;
        c++;
    }
    return data;

}

int* splitStringToInt(string str, char s) {
    int size = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == s) size++;
    }
    int* marks = new int[size+1];
    string curStr;
    int c = 0;
    for (int j = 0; j < size+1; j++) {
        curStr = "";
        while (str[c] != '\n' && str[c] != s && str[c] != '\0') {
            curStr += str[c++];
        }
        marks[j] = stoi(curStr);
        c++;
    }
    return marks;

}

Group createGroup(string name) {
    string str = "";
    for (int i = 1; i < name.size(); i++) {
        str += name[i];
    }
    Group gr(str);
    return gr;
}

Journal createJournal(string path) {
    int groupCount = -1;
    string* fileArray = readFile(path);
    Journal journal("Математика", "Ирина");
    for (int i = 1; i < stoi(fileArray[0]); i++) {
        if (fileArray[i][0] == '.') {
            groupCount++;
            journal.addGroup(createGroup(fileArray[i]));
        }
        else {
            journal.
        }
    }
    return journal;
}

int main()
{
    locale::global(locale(".utf8"));
    string path = "classes.txt";
    //string* fileArray = readFile(path);

    Journal math = createJournal(path);
    math.info();

    //showArray(fileArray);
    /*string* test = split(fileArray[2], ';');
    cout << test[0] << endl;
    cout << test[1] << endl;
    cout << test[2] << endl;
    cout << test[3] << endl;
    cout << test[4] << endl;
    cout << test[5] << endl;
    int* testMarks = splitStringToInt(test[5], ',');
    for (int i = 0; i < 7; i++) {
        cout << testMarks[i] << " ";
    }*/
}
