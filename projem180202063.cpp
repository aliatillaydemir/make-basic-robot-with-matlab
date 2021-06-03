#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

void q1()
{
    srand((unsigned int)time(0));

    MatrixXd m = MatrixXd::Random(5, 8) * 100;
    MatrixXi min = m.cast<int>().array().abs();
    cout << "min =" << endl << min << endl;

}

/*
void q2()
{
    srand((unsigned int)time(0));
    MatrixXd A = MatrixXd::Random(5*4,3) * 100;
    double A0 = A.block<5, 4>(0 *3, 0);
    cout << "A = " << endl << A0  << endl;


}
*/
void q3()
{

    Array<float, 10, 10> a = Array<float, 10, 10>::Random(10, 10) * 100;
    float max = a.maxCoeff(), min = a.minCoeff();
    cout << a << endl << endl << "min:" << min << endl << "max:" << max << endl;

}
void q4()
{
    srand((unsigned int)time(0));
    MatrixXd m = MatrixXd::Random(5, 3) * 10;
    MatrixXi mi = m.cast<int>().array().abs();


    MatrixXd m2 = MatrixXd::Random(3, 2) * 10;
    MatrixXi mt = m2.cast<int>().array().abs();

    cout << "mi : " << endl << mi << endl;
    cout << "mt : " << endl << mt << endl;

    std::cout << "Matrislerin Carpimi \n"
        << mi * mt << std::endl;

}


void q5()
{
    srand((unsigned int)time(0));
    Matrix<float, 10, 1> Vector = VectorXf::Random(10, 1) * 10;
    int indis;

    Vector.maxCoeff(&indis);
    cout << endl << Vector << endl;
    Vector(indis) = 0;
    cout << endl << Vector << endl;

}



void q6()
{
    MatrixXi MM = MatrixXi::Ones(100, 150);
    for (int i = 0; i < MM.rows(); ++i) {
        for (int j = 0; j < MM.cols(); ++j)
        {
            MM(i, j) = i + 1;

        }
    }
    cout << MM << endl;

}


void q7()
{
    MatrixXi MM = MatrixXi::Ones(100, 150);
    for (int i = 0; i < MM.rows(); ++i) {
        for (int j = 0; j < MM.cols(); ++j)
        {
            MM(i, j) = i + 1;

        }
    }
    cout << MM << endl;

    MatrixXi sag_ust = MatrixXi::Ones(25, 25);
    MatrixXi sag_alt = MatrixXi::Ones(25, 25);
    MatrixXi sol_ust = MatrixXi::Ones(25, 25);
    MatrixXi sol_alt = MatrixXi::Ones(25, 25);

    sol_ust = MM.leftCols(25).topRows(25);
    sol_alt = MM.leftCols(25).bottomRows(25);
    sag_ust = MM.rightCols(25).topRows(25);
    sag_alt = MM.rightCols(25).bottomRows(25);


    cout << "sag ust " << endl << sag_ust << endl << endl;
    cout << "sag alt " << endl << sag_alt << endl << endl;
    cout << "sol ust " << endl << sol_ust << endl << endl;
    cout << "sol alt " << endl << sol_alt << endl << endl;

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            MM(i, j) = sag_alt(i, j);
        }
    }

    cout << "MM -> sag alt sol ustun yerine geldi" << endl << MM << endl << endl;

    int l = 0, m = 0;
    for (int i = 75; i < 100; i++) {
        for (int j = 125; j < 150; j++) {
            MM(i, j) = sol_ust(l, m);
            m++;
        }
        m = 0;
        l++;
    }

    cout << "MM -> sol ust sag altin yerine geldi" << endl << MM << endl << endl;

    l = 0, m = 0;
    for (int i = 0; i < 25; i++) {
        for (int j = 125; j < 150; j++) {
            MM(i, j) = sol_alt(l, m);
            m++;
        }
        m = 0;
        l++;
    }

    cout << "MM -> sol alt sag ustun yerine geldi" << endl << MM << endl << endl;

    l = 0, m = 0;
    for (int i = 75; i < 100; i++) {
        for (int j = 0; j < 25; j++) {
            MM(i, j) = sag_ust(l, m);
            m++;
        }
        m = 0;
        l++;
    }

    cout << "MM -> sag ust sol altin yerine geldi ve matrisin son hali : " << endl << MM << endl << endl;

}


void q8()
{
    MatrixXd sekiz = MatrixXd::Random(10, 10) * 100;
    MatrixXi sekizi = sekiz.cast<int>().array().abs();
    cout << "sekiz =\n" << sekizi << endl;
    sekizi = sekizi.transpose().eval();
    cout << "\nsekizin transposesi =\n" << sekizi << endl;

}

void q10()
{
    Array<float, 10, 10> a = Array<float, 10, 10>::Random(10, 10) * 100;
    cout << "soru10" << endl << a << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a(i, j) < 0)
                a(i, j) = -a(i, j);
        }
    }
    cout << "soru10 2. kisim" << endl << a << endl;
}

void q11() {
    /*
    for(i=0;i<boyut;i++){
        key=i;
        for(j=i+1;j<boyut;j++){
            if(dizi[key]>dizi[j])
                key=j;
        }
        temp=dizi[key];
        dizi[key]=dizi[i];
        dizi[i]=temp;

    }
    }*/


    srand((unsigned int)time(0));
    Array<float, 10, 10> dizi = Array<float, 10, 10>::Random(10, 10) * 100;
    cout << "soru11 v1" << endl << dizi << endl;

    int key = 0;
    float temp = 0;
    //q satýr i sutun


    for (int q = 0; q < 10; q++) {
        for (int i = 0; i < 10; i++) {

            key = i;
            for (int j = i + 1; j < 10; j++) {

                if (dizi(q, key) > dizi(q, j))
                    key = j;

            }

            temp = dizi(q, key);
            dizi(q, key) = dizi(q, i);
            dizi(q, i) = temp;

        }
    }


    cout << "soru11 v2" << endl << dizi << endl;

}


int main()
{
    q1();
    //q3();
    //q4();
    //q5();
    //q6();
    //q7();
    //q8();
    //q10();
    //q11();
}