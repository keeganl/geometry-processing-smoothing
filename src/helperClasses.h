class Tri
{
public:
  int e1;
  int e2;
  int e3;
  double e1Length;
  double e2Length;
  double e3Length;
  double area;

  Tri(int a, int b, int c, double ar)
  {
    e1 = a;
    e2 = b;
    e3 = c;
    area = ar;
  }
};

class Edge {
  int i;
  int j;
};