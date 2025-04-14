#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

template <typename E>
class Setdata // 设置实验数据
{
public:
    vector<E> Set_Data()
    {
        vector<E> Experment_Data;
        E temp;
        while (cin >> temp)
        {
            Experment_Data.push_back(temp);
            if (cin.get() == '\n')
            {
                break;
            }
        }
        return Experment_Data;
    }
};

template <typename E>
class solid_laser : protected Setdata<E> // 固体激光实验处理类
{
private:
    vector<E> U_in;       // 输入电压
    vector<E> T;          // 脉宽
    const double c = 0.1; // 单位为mF
public:
    vector<E> E_out; // 输出能量
    void Set_in()
    {
        cout << "请输入注入电压实验数据(输入回车以结束):";
        U_in = Setdata<E>::Set_Data();
    }
    void Set_out()
    {
        cout << "请输入输出能量实验数据(输入回车以结束):";
        E_out = Setdata<E>::Set_Data();
    }
    void Set_T()
    {
        cout << "请输入脉宽实验数据(输入回车以结束):";
        T = Setdata<E>::Set_Data();
    }
    void E_in() // 输入电压与注入能量转化公式
    {
        for (int i = 0; i < U_in.size(); i++)
        {
            cout << 0.5 * c * pow(U_in[i], 2) << "  ";
        }
        cout << endl;
    }

    void P_peek() // 峰值功率函数
    {
        for (int i = 0; i < U_in.size(); i++)
        {
            cout << E_out[i] / (T[i] * 1e-3) << "  ";
        }
        cout << endl;
    }
    void P_peek(int a) // 峰值功率函数
    {
        for (int i = 0; i < U_in.size(); i++)
        {
            cout << E_out[i] / (T[i] * 1e-6) << "  ";
        }
        cout << endl;
    }

    void dy_sta_ratio(vector<E> E_out_dy, vector<E> E_out_st) // 动静比函数
    {
        for (int i = 0; i < min(E_out_dy.size(), E_out_st.size()); i++)
        {
            cout << E_out_dy[i] / E_out_st[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    solid_laser<double> U_dy, U_sta;
    cout << "静态实验数据:\n";
    U_sta.Set_in();
    U_sta.Set_out();
    U_sta.Set_T();
    cout << "动态实验数据:\n";
    U_dy.Set_in();
    U_dy.Set_out();
    U_dy.Set_T();
    cout << "静态实验结果:\n";
    cout << "  " << "静态注入能量:" << endl;
    U_sta.E_in();
    cout << "  " << "静态峰值功率:" << endl;
    U_sta.P_peek();
    cout << "动态实验结果:\n";
    cout << "  " << "动态注入能量:" << endl;
    U_dy.E_in();
    cout << "  " << "动态峰值功率:" << endl;
    U_dy.P_peek(1);

    cout << "动静比:" << endl;
    U_dy.dy_sta_ratio(U_dy.E_out, U_sta.E_out);

    return 0;
}