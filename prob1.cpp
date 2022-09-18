#include <iostream>

using namespace std;

template <class T>
class Queue {
public:
    virtual void enqueue(T item) = 0;      // เพิ่มสมาชิกลงไปท้ายคิว
    virtual T  dequeue() = 0;               // เอาสมาชิกหน้าสุดออกจากคิว
    virtual T  front() = 0;               // ดูข้อมูลสมาชิกตัวหน้าสุดของคิว
    virtual bool empty() = 0;           // ตรวจสอบว่า Stack ว่างหรือไม่
    virtual void clear() = 0;           // ลบข้อมูลทั้งหมด
};

template <class T>
class ArrayQueue : public Queue<T> {
    T *Q;
    int n;
public:
    int F,R;
    ArrayQueue(int size) {
        Q = new T[size];
        n=size;
        F=0;
        R=0;
    }
    ~ArrayQueue() {
        delete [ ] Q;
    }
    bool empty();
    void clear();
    void enqueue(T item);
    T  dequeue( );
    T  front();
};
template <class T>
bool ArrayQueue<T>::empty() {
    return F==R;
}

template <class T>
void ArrayQueue<T>::clear() {
    F=0;
    R=0;
}
template <class T>
// แก้ไข code ให้เป็น Queue แบบวงกลม
// ดูตัวอย่างที่ 4.7 ในหนังสือ หน้า 92
void ArrayQueue<T>::enqueue(T item) {
    int Rnew = R+1;
    if(Rnew == n ) {
        Rnew=0;
    }
    if(Rnew == F) {
        cout << "Queue overflow.\n";
        return;
    }
    Q[R]=item;
    R=Rnew+1;
}

template <class T>
T ArrayQueue<T>::dequeue() {
    // แก้ไข codeดูตัวอย่างที่ 4.8 ในหนังสือ หน้า 93
    if(empty()) {
        cout << "Queue is empty.\n";
        return T();
    }
    T tmp = Q[F];
    F++;
    if(F>=n) {
        F=0;
    }
    return tmp;
}

template <class T>
T ArrayQueue<T>::front() {
    if(empty()) {
        cout << "Queue is empty.\n";
        return T();
    }
    return Q[F];
}

int main() {
    ArrayQueue<string> q1(15);
    for(int i=0; i<10; i++) {
        string x;
        cin >> x;
        q1.enqueue(x);
        cout << "q1.enqueue " << x << " q1.R = "<< q1.R << endl;
    }
    for(int i=0; i<5; i++) {
        cout << "q1.dequeue = " << q1.dequeue() << " q1.F = "<< q1.F << endl;
    }
    for(int i=0; i<8; i++) {
        string x;
        cin >> x;
        q1.enqueue(x);
        cout << "q1.enqueue " << x << " q1.R = "<< q1.R << endl;
    }
    while(!q1.empty()) {
        cout << "q1.dequeue = " << q1.front() << " q1.F = "<< q1.F << endl;
        q1.dequeue();
    }
    cout << endl;
    return 0;
}
