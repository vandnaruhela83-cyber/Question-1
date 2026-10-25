#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>   // sort, reverse
using namespace std;

// Helper: prints a label followed by all elements of a vector
void print(const string& label, const vector<int>& v) {
    cout << label << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    // =====================================================
    // 1. CREATING A VECTOR (constructors)
    // =====================================================
    cout << "--- 1. Constructors ---" << endl;
    vector<int> a;                    // empty vector
    vector<int> b(5, 10);             // 5 elements, each = 10
    vector<int> c = {1, 2, 3, 4, 5};  // initializer list
    vector<int> d(c);                 // copy of c
    vector<int> e(c.begin() + 1, c.begin() + 4);  // range copy: 2 3 4

    print("a (empty)", a);
    print("b (5 x 10)", b);
    print("c (list)", c);
    print("d (copy of c)", d);
    print("e (range)", e);

    // =====================================================
    // 2. ELEMENT ACCESS
    // =====================================================
    cout << "\n--- 2. Element access ---" << endl;
    cout << "c[2]      = " << c[2] << endl;       // no bounds checking
    cout << "c.at(3)   = " << c.at(3) << endl;    // bounds checked
    cout << "c.front() = " << c.front() << endl;  // first element
    cout << "c.back()  = " << c.back() << endl;   // last element
    int* p = c.data();                            // pointer to internal array
    cout << "*(c.data()+1) = " << *(p + 1) << endl;

    try {
        c.at(10);                                 // out of range
    } catch (const out_of_range& ex) {
        cout << "at(10) threw out_of_range" << endl;
    }

    // =====================================================
    // 3. CAPACITY
    // =====================================================
    cout << "\n--- 3. Capacity ---" << endl;
    vector<int> v;
    cout << "empty()    = " << v.empty() << endl;      // 1 (true)
    v.reserve(20);                                    // allocate space for 20
    cout << "after reserve(20): size=" << v.size()
         << ", capacity=" << v.capacity() << endl;
    v.resize(5);                                      // size becomes 5 (new = 0)
    print("after resize(5)", v);
    v.resize(7, 99);                                  // grow to 7, new = 99
    print("after resize(7, 99)", v);
    v.resize(3);                                      // shrink to 3
    print("after resize(3)", v);
    v.shrink_to_fit();                                // capacity -> size
    cout << "after shrink_to_fit: size=" << v.size()
         << ", capacity=" << v.capacity() << endl;
    cout << "max_size() > 0 : " << (v.max_size() > 0) << endl;

    // =====================================================
    // 4. MODIFIERS
    // =====================================================
    cout << "\n--- 4. Modifiers ---" << endl;
    vector<int> m;

    m.push_back(10);                 // add at end
    m.push_back(20);
    m.push_back(30);
    print("push_back x3", m);

    m.pop_back();                    // remove last
    print("pop_back", m);

    m.insert(m.begin(), 5);          // insert 5 at front
    print("insert(begin, 5)", m);

    m.insert(m.begin() + 2, 3, 7);   // insert three 7s at index 2
    print("insert(begin+2, 3, 7)", m);

    m.erase(m.begin());              // erase first element
    print("erase(begin)", m);

    m.erase(m.begin() + 1, m.begin() + 3);   // erase range [1, 3)
    print("erase(range)", m);

    m.emplace_back(40);              // construct in place at end
    m.emplace(m.begin(), 1);         // construct in place at position
    print("emplace_back / emplace", m);

    m.assign(4, 8);                  // replace contents with four 8s
    print("assign(4, 8)", m);

    vector<int> x = {1, 2, 3};
    vector<int> y = {9, 8};
    x.swap(y);                       // exchange contents
    print("x after swap", x);
    print("y after swap", y);

    m.clear();                       // remove all elements
    cout << "after clear: size=" << m.size() << endl;

    // =====================================================
    // 5. ITERATORS
    // =====================================================
    cout << "\n--- 5. Iterators ---" << endl;
    vector<int> it_v = {10, 20, 30, 40};

    cout << "forward (begin..end): ";
    for (auto it = it_v.begin(); it != it_v.end(); ++it) cout << *it << " ";
    cout << endl;

    cout << "reverse (rbegin..rend): ";
    for (auto it = it_v.rbegin(); it != it_v.rend(); ++it) cout << *it << " ";
    cout << endl;

    cout << "const (cbegin..cend): ";
    for (auto it = it_v.cbegin(); it != it_v.cend(); ++it) cout << *it << " ";
    cout << endl;

    // =====================================================
    // 6. OPERATORS & USEFUL ALGORITHMS
    // =====================================================
    cout << "\n--- 6. Operators and algorithms ---" << endl;
    vector<int> p1 = {1, 2, 3};
    vector<int> p2 = {1, 2, 3};
    cout << "p1 == p2 : " << (p1 == p2) << endl;
    p2 = {4, 5};                     // assignment operator
    print("p2 after assignment", p2);

    vector<int> s = {5, 2, 9, 1, 7};
    sort(s.begin(), s.end());
    print("sort", s);
    reverse(s.begin(), s.end());
    print("reverse", s);

    return 0;
}
