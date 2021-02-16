double cos(double a, double b, double c)
{
  double a2 = pow(a, 2);
  double b2 = pow(b, 2);
  double c2 = pow(c, 2);

  return ((a2 + b2 + c2) / (2 * a * b));
}

double sin(double a, double b, double c)
{
  double a2 = pow(a, 2);
  double b2 = pow(b, 2);
  double c2 = pow(c, 2);

  return (sqrt((4 * a2 * b2) - pow((a2 + b2 - c2), 2)) / (2 * a * b));
}

double cot(double a, double b, double c)
{
  return cos(a, b, c) / sin(a, b, c);
}

double perimeter(double a, double b, double c)
{
  return ((a + b + c) / 2);
}

double area(double a, double b, double c)
{
  double p = perimeter(a, b, c);
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

// float cotan(const Vec3 a, const Vec3 b)
// {
//   return a.dot(b)) / (a.cross(b)).norm();
// }