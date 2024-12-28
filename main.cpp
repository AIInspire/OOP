#include <iostream>
#include <cstring> // For string handling functions

using namespace std;

class student
{
    int id;
    char *name;
    int s;         // Number of grades
    float *grad;   // Array to store grades

public:
    // Default constructor
    student()
    {
        id = 0;
        s = 0;
        grad = nullptr; // Initialize to nullptr
        name = nullptr; // Initialize to nullptr
    }

    // Parameterized constructor
    student(int s_id, int size_grads, const char *s_name)
    {
        id = s_id;
        s = size_grads;
        grad = new float[s];
        name = new char[strlen(s_name) + 1];
        strcpy(name, s_name); // Copy the name
    }

    // Copy constructor
    student(const student &rst)
    {
        id = rst.id;
        s = rst.s;
        grad = new float[s];
        for (int i = 0; i < s; i++)
        {
            grad[i] = rst.grad[i];
        }
        name = new char[strlen(rst.name) + 1];
        strcpy(name, rst.name); // Copy the name
    }

    // Destructor
    ~student()
    {
        delete[] grad;
        delete[] name;
    }

    void set_id(int s_id)
    {
        id = s_id;
    }

    void set_size(int g_size)
    {
        if (grad) delete[] grad; // Free existing memory
        s = g_size;
        grad = new float[s];
    }

    void set_grad(int ind, float g)
    {
        if ((ind >= 0) && (ind < s))
        {
            grad[ind] = g;
        }
        else
        {
            cerr << "Index out of bounds!" << endl;
        }
    }

    void set_name(const char *s_name)
    {
        if (name) delete[] name; // Free existing memory
        name = new char[strlen(s_name) + 1];
        strcpy(name, s_name);
    }

    int get_id() const
    {
        return id;
    }

    int get_size() const
    {
        return s;
    }

    float get_grad(int ind) const
    {
        if ((ind >= 0) && (ind < s))
        {
            return grad[ind];
        }
        else
        {
            cerr << "Index out of bounds!" << endl;
            return -1; // Return an invalid value to indicate error
        }
    }

    const char* get_name() const
    {
        return name;
    }
};

// Function to fill a student object with user input
student fill_student()
{
    int id, size;
    char name[100]; // Temporary array to store the name
    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student name: ";
    cin.ignore(); // Clear the newline character
    cin.getline(name, 100);

    cout << "Enter the number of grades: ";
    cin >> size;

    student s(id, size, name);
    for (int i = 0; i < size; i++)
    {
        float grade;
        cout << "Enter grade " << i + 1 << ": ";
        cin >> grade;
        s.set_grad(i, grade);
    }

    return s;
}

// Function to print student details
void print_student(const student &s)
{
    cout << "Student ID: " << s.get_id() << endl;
    cout << "Student Name: " << s.get_name() << endl;
    cout << "Grades: ";
    for (int i = 0; i < s.get_size(); i++)
    {
        cout << s.get_grad(i) << " ";
    }
    cout << endl;
}

int main()
{
    // Create and fill a student object
    student s = fill_student();

    // Print student details
    print_student(s);

    // Test copy constructor
    student s_copy(s);
    cout << "Copied Student Details:" << endl;
    print_student(s_copy);

    return 0;
}
