#include <iostream>
#include <string>

using namespace std;

class CVertex {
public:
    CVertex(int x, int y, int z):m_x(x),m_y(y),m_z(z) {}
    virtual ~CVertex() {}

public:
    int getX(void){
        return m_x;
    }
    int getY(void){
        return m_y;
    }
    int getZ(void){
        return m_z;
    }

    void setX(int x) {
        m_x = x;
    }
    void setY(int y) {
        m_y = y;
    }
    void setZ(int z) {
        m_z = z;
    }

private:
    int m_x;
    int m_y;
    int m_z;
};

int main()
{
    int a = 7;
    int b =100;
    int* ptr = &a;
    int& ref = a;
    ref = b;
    int array[3][3] = {
        {1,2,3,},
        {4,5,6,},
        {7,8,9,},
    };
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    CVertex vtx(1,2,3);
    cout << "x=" << vtx.getX() << ",";
    cout << "y=" << vtx.getY() << ",";
    cout << "z=" << vtx.getZ() << endl;
    return 0;
}
