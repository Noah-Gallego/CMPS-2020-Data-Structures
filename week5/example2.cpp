#include <iostream>
#include <cmath>

using namespace std;

class QuadraticException : public exception {
    public: 
        const char *what() const throw() {
            return "Quadratic Error";
        }
};

class DenomException : public QuadraticException {
    public:
        const char *what() const throw() {
            return "Bad Denominator";
        }
};

class DiscException : public QuadraticException {
    public:
        const char *what() const throw() {
            return "Bad Discriminant";
        }
};

class Quadratic {
    private:
        double a, b, c;

        double calcRoot1() {
            double denom = 2 * a;
            double discriminant = b * b -4 * a * c;
            double result;

            if(denom == 0)
                throw DenomException();

            result = (-b + sqrt(discriminant)) / denom;
            return result;
        }

        double calcRoot2() {
            double denom = 2 * a;
            double discriminant = b * b -4 * a * c;
            double result;

            if(denom == 0)
                throw DenomException();

            result = (-b - sqrt(discriminant)) / denom;
            return result;
        }
    public:
        Quadratic(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {};
        void solve(double &root1, double &root2) {
            root1 = calcRoot1();
            root2 = calcRoot2();
        }
};

int main() {
    Quadratic q(2, 0, 0);

    double root1, root2;

    try {
        q.solve(root1, root2);
    } catch (DenomException &ex) {
        cerr << ex.what() << endl;
    } catch (DiscException &ex) {
        cerr << ex.what() << endl;
    } catch (...) {
        cerr << "Uh Oh. Something Happened :(" << endl;
    }
    

    return 0;
}