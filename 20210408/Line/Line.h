#ifndef __LINE_H__
#define __LINE_H__

class Line
{
public:
    Line(int x1, int y1, int x2, int y2);
    void printLine() const;
    ~Line();
    class LineImpl;//类的前向声明
private:
    LineImpl *_pimpl;
};
#endif
