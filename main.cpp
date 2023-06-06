#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    int n = 9;
    ifstream f;
    ofstream p;
    f.open("D:/test/10.txt");
    auto* x = new float[n];
    auto* y = new float[n];
    float x_ = 0;
    float y_ = 0;
    float xy_ = 0;
    float xx_ = 0;
    float a = 0, a1 = 0;

    for (int i = 0; i < n; i++){
        f >> x[i];
        x_ += x[i];
        xx_ += x[i]*x[i];
    }

    for (int i = 0; i < n; i++){
        f >> y[i];
        y_ += y[i];
    }

    for (int i = 0; i < n; i++){
        xy_ += x[i]*y[i];
    }

    a1 = (n*xy_ - x_*y_)/(n*xx_ - x_*x_);
    a = y_/(float)n - a1*x_/(float)n;

    for (int i = 0; i< n; i++){
        p << a + a1*x[i] << " ";
    }
    cout << "�������� ॣ����: " << a << "+" << a1 << "x"<< endl;

    float kor = 0, mx = 0, my = 0;
    for (int i =0; i < n; i++){
        kor += (x[i] - x_/(float)n)*(y[i] - y_/(float)n);
        mx += (x[i] - x_/(float)n)*(x[i] - x_/(float)n);
        my += (y[i] - y_/(float)n)*(y[i] - y_/(float)n);
    }
    kor /= sqrt(mx*my);

    cout << "�����樥�� ���५�樨: " << kor << endl;

    float sse = 0, mae = 0;

    for (int i = 0; i < n; i++){
        sse += (y[i] - a - a1*x[i])*(y[i] - a - a1*x[i]);
    }
    mae = sse / n;
    cout << "�㬬�ୠ� ������筠� �訡�� ��� �������� ॣ��ᨨ: " << sse << endl;
    cout << "�।��� ������筠� �訡�� ��� �������� ॣ��ᨨ: " << mae << endl;

    float lnx_ = 0;
    float lny_ = 0;
    float lnxy_ = 0;
    float lnxx_ = 0;
    float lna = 0, lna1 = 0;

    for (int i = 0; i < n; i++){
        lnx_ += log(x[i]);
        lnxx_ += log(x[i])*log(x[i]);
    }

    for (int i = 0; i < n; i++){
        lny_ += log(y[i]);
    }

    for (int i = 0; i < n; i++){
        xy_ += log(x[i])*log(y[i]);
    }

    a1 = (n*lnxy_ - lnx_*lny_)/(n*lnxx_ - lnx_*lnx_);
    a = exp(lny_/(float)n - a1*lnx_/(float)n);

    cout << "�㭪樮���쭠� ����ᨬ���� ����� ���: y=" <<a << "x^" << a1<< endl;
    for (int i = 0; i < n; i++){
        sse += (y[i] - a*pow(x[i], a1))*(y[i] - a*pow(x[i], a1));
    }
    mae = sse / n;
    cout << "�㬬�ୠ� ������筠� �訡�� ��� �������� ॣ��ᨨ: " << sse << endl;
    cout << "�।��� ������筠� �訡�� ��� �������� ॣ��ᨨ: " << mae << endl;
}
