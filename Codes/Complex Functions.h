#include <iostream>
#include <math.h>

using namespace std;

class complex
{
private:
    double real;
    double img;
public:
    complex(double _real, double _img){real=_real; img=_img;};
    double get_real()const {return real;};
    double get_img()const {return img;};
    double calc_phase(){return atan2(img,real);};
    friend void print(complex c)
    {   if (c.img > 0){cout<<c.real<<"+"<<c.img<<"i";}
        else{cout<<c.real<<c.img<<"i";}
    };
    complex operator+(const complex& num)
    {   double real_sum=(this->get_real()+num.get_real());
        double img_sum=(this->get_img()+num.get_img());
        return complex(real_sum,img_sum);
    };
    complex operator*(const complex& num)
    {   double real_mult=((this->get_real()*num.get_real())-(this->get_img()*num.get_img()));
        double img_mult=((this->get_real()*num.get_img())+(this->get_img()*num.get_real()));
        return complex(real_mult,img_mult);
    };
};

int main()
{
    complex c1(4,-5);
    complex c2(2,9);
    cout<<"c1: "; print(c1); cout<<endl;
    cout<<"c2: "; print(c2); cout<<endl;
    cout<<"phase c1: "<<c1.calc_phase()<<endl;
    cout<<"phase c2: "<<c2.calc_phase()<<endl;
    cout<<"c1+c2: "; print(c1+c2); cout<<endl;
    cout<<"c1*c2: "; print(c1*c2); cout<<endl;
}
