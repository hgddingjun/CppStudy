#include <iostream>

using namespace std;

class CShape {
public:
    CShape() {}
    virtual void draw() = 0;
    virtual void rotate(int angle) = 0;
    virtual move(Point to) = 0;
    virtual ~CShape() {}
};

class CCircle : public CShape {
public:
    CCircle(Point p, int radius)
    {

    }
    ~CCircle() = default;

    virtual void draw();
    virtual void rotate(int angle);
    virtual void move (Point to)
    {
        x = to;
    }

private:
    Point x;
    int r;
};

class CSmileFace : public CCircle {
public:
    CSmileFace(Point p, int r)
    : CCircle(p, r), mouth(nullptr) {}
    ~CSmileFace() {
        delete mouth;
        for(auto p : eyes)
            delete p;
    }
    void move(Point to);
    void draw();
    void rotate(int);
    void add_eye(CShape* s) {
        eyes.push_back(s);
    }
    void set_mouth(CShape* s);
    virtual void wink(int i);

private:
    vector<CShape *> eyes;
    CShape* mouth;
};

void CSmileFace::draw()
{
    CCircle::draw();
    for(auto p : eyes)
        p->draw();
    mouth->draw();
}

void rotate_all(vector<CShape *>& v, int angle)
{
    for(auto& p : v)
    {
        p->rotate(angle);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
