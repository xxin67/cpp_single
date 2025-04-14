#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
using namespace std;
#define R 4 // 设晶胞长度为4个晶格常量,可分为4部分,从晶体结构可知每一部分各有特点,故可用取模来分别处理每一部分

vector<int> cul_n(int n) // 平方预制表制作函数
{
    vector<int> temp(n + 2);
    generate(temp.begin(), temp.end(), [init = -1]() mutable
             { return ++init * init; });
    return temp;
}
vector<int> n_num; // 平方预制表

class K3C60
{
private:
    int m, l, i, j, k, flag, n1, n2, n3;
    long x;
    double r, a = 0, ratio = 1, aver;
    vector<double> a_array, average;
    long cnt = 0;

    inline int convertflag_k(long x) // 电荷翻转
    {
        return (x % 2 == 1) ? 1 : -3;
    }

    inline int convertflag_c60(long x) // 用以转化flag
    {
        return (x % 2 == 1) ? 9 : -3;
    }

public:
    ~K3C60() {}
    double result_k1(int n)
    {
        for (l = 2; l <= n / 2; l++)
        {
            int m = 2 * l;
            cnt++;
            a = 0.0; // 重置a为当前层的累加

            if (l % 2 == 0) // 判断最外层是c60-k1面(=0)还是k2面(!=0)
            {
                // 处理C60-K1面
                if (l % 4 == 0) // 判断最外层顶点是否同号(=0同!=0不同)
                {
                    flag = 1; // 电荷因子异同标记
                    x = 0;    // x为转化信号量,用以根据条件快速变化flag
                }
                else
                {
                    flag = -3;
                    x = 1;
                }

                for (i = -l; i <= l; i += 2) // 从最左向最有右遍历
                {
                    n1 = i;
                    int abs_n1 = abs(n1);
                    for (j = -l; j <= l; j += 2) // 从最外向最里遍历
                    {
                        n2 = j;
                        int abs_n2 = abs(j);
                        for (k = -l; k <= l; k += 2) // 从最下向最上遍历
                        {
                            n3 = k;
                            int abs_n3 = abs(k);
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq == 0)
                            {
                                flag = convertflag_k(x++);
                                continue;
                            }
                            double r = sqrt(sum_sq);
                            int edge_count = (abs_n1 == l) + (abs_n2 == l) + (abs_n3 == l);
                            double ratio = 1.0 / (1 << edge_count); // 判断边缘离子
                            a += -flag * ratio * R / r;             // 依次计算c60与k1的作用势能
                            flag = convertflag_k(x++);              // 由晶体结构可知相邻点的电荷相反,故循环每进一步,flag进行变化
                        }
                    }
                }
                // 处理K2面，无需边界判断
                for (i = -l + 1; i <= l - 1; i += 2) // 因为起始位c60与k1面,故下一部分为k2面
                {
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            double r = sqrt(sum_sq);
                            a += -1.0 * R / r; // ratio = 1.0,k2面肯定不是边缘,故无需权重
                        }
                    }
                }
            }

            else // 起始面为k2
            {
                // 处理K2面（作为起始面）
                for (i = -l; i <= l; i += 2)
                {
                    n1 = i;
                    int abs_n1 = abs(n1);
                    for (j = -l; j <= l; j += 2)
                    {
                        n2 = j;
                        int abs_n2 = abs(j);
                        for (k = -l; k <= l; k += 2)
                        {
                            n3 = k;
                            int abs_n3 = abs(k);
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            double r = sqrt(sum_sq);
                            int edge_count = (abs_n1 == l) + (abs_n2 == l) + (abs_n3 == l);
                            double ratio = 1.0 / (1 << edge_count);
                            a += -1.0 * ratio * R / r;
                        }
                    }
                }

                // 处理K1和C60面
                if ((l - 1) % 4 == 0) // 判断次外层顶点同号
                {
                    flag = 1;
                    x = 0;
                }
                else
                {
                    flag = -3;
                    x = 1;
                }

                for (i = -l + 1; i <= l - 1; i += 2)
                {
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq == 0)
                            {
                                flag = convertflag_k(x++);
                                continue;
                            }
                            double r = sqrt(sum_sq);
                            a += -flag * R / r; // ratio = 1.0
                            flag = convertflag_k(x++);
                        }
                    }
                }
            }

            a_array.push_back(a);                     // 存放每一次循环结果
            cout << "m=" << m << "\ta=" << a << endl; // 输出m,a

            if (cnt % 4 == 0) // 每八次求一次均值
            {
                double sum = accumulate(a_array.end() - 4, a_array.end(), 0.0);
                aver = sum / 4.0;
                average.push_back(aver); // 将每个均值记录
                cout << "K1 result's average = " << setprecision(10) << aver << endl;
            }
        }

        cout << endl;
        if (!a_array.empty()) // 将最后十个均值求平均
        {
            double sum = accumulate(average.end() - 8, average.end(), 0.0);
            aver = sum / 8;
            cout << "K1 final result = " << aver << endl;
        }
        return aver;
        cout << endl;
    }

    double result_c60(int n)
    {
        for (l = 2; l <= n / 2; l++)
        {
            m = 2 * l;
            cnt++;
            a=0.0;

            if (l % 2 == 0) // 判断最外层是c60-k1面(=0)还是k2面(!=0)
            {
                // 计算c60与k1之间的作用能
                if (l % 4 == 0) // 判断最外层顶点是否同号(=0同!=0不同)
                {
                    flag = 9; // 电荷因子异同标记
                    x = 0;    // x为转化信号量,用以根据条件快速变化flag
                }
                else
                {
                    flag = -3;
                    x = 1;
                }

                for (i = -l; i <= l; i += 2) // 从最左向最有右遍历
                {
                    for (j = -l; j <= l; j += 2) // 从最外向最里遍历
                    {
                        for (k = -l; k <= l; k += 2) // 从最下向最上遍历
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq == 0)
                            {
                                flag = convertflag_c60(x++);
                                continue;
                            }
                            r = sqrt(sum_sq);
                            int edge_count = (abs(i) == l) + (abs(k) == l) + (abs(j) == l);
                            double ratio = 1.0 / (1 << edge_count); // 判断边缘离子
                            a += -flag * ratio * R / r;             // 依次计算c60与k1的作用势能
                            flag = convertflag_c60(x++); // 由晶体结构可知相邻点的电荷相反,故循环每进一步,flag进行变化
                        }
                    }
                }
                // 计算与k2的作用能
                for (i = -l + 1; i <= l - 1; i += 2) // 因为起始位c60与k1面,故下一部分为k2面
                {
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            double r = sqrt(sum_sq);
                            a += 3 * R / r; // k2面肯定不是边缘,故无需权重
                        }
                    }
                }
            }
            else // 起始面为k2
            {
                /* 计算与k2相互作用 */
                for (i = -l; i <= l; i += 2)
                {
                    for (j = -l; j <= l; j += 2)
                    {
                        for (k = -l; k <= l; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            r = sqrt(sum_sq);
                            int edge_count = (abs(i) == l) + (abs(k) == l) + (abs(j) == l);
                            double ratio = 1.0 / (1 << edge_count);
                            a += 3 * ratio * R / r; // 同理
                        }
                    }
                }
                /* 计算与k1,c60面相互作用 */
                if ((l - 1) % 4 == 0) // 判断次外层顶点同号
                {
                    flag = 9;
                    x = 0;
                }
                else
                {
                    flag = -3;
                    x = 1;
                }

                for (i = -l + 1; i <= l - 1; i += 2)
                {
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq == 0)
                            {
                                flag = convertflag_c60(x++);
                                continue;
                            }
                            r = sqrt(sum_sq);
                            a += -flag * R / r;
                            flag = convertflag_c60(x++);
                        }
                    }
                }
            }

            a_array.push_back(a);                     // 存放每一次循环结果
            cout << "m=" << m << "\ta=" << a << endl; // 输出m,a

            if (cnt % 4 == 0) // 每八次求一次均值
            {
                double sum = accumulate(a_array.end() - 4, a_array.end(), 0.0);
                aver = sum / 4;
                average.push_back(aver); // 将每个均值记录
                cout << "C60 result's average = " << setprecision(10) << aver << endl;
            }
        }

        cout << endl;
        if (!a_array.empty()) // 将最后十个均值求平均
        {
            double sum = accumulate(average.end() - 8, average.end(), 0.0);
            aver = sum / 8;
            cout << "C60 final result = " << aver << endl;
        }
        return aver;
        cout << endl;
    }

    double result_k2(int n)
    {
        for (l = 2; l <= n / 2; l++)
        {
            m = 2 * l;
            cnt++;
            a=0.0;

            if (l % 2 == 0) // 当最外层为K2时
            {
                for (i = -l; i <= l; i += 2) // 从最左向最有右遍历
                {
                    for (j = -l; j <= l; j += 2) // 从最外向最里遍历
                    {
                        for (k = -l; k <= l; k += 2) // 从最下向最上遍历
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq==0)
                            {
                                continue;
                            }
                            r = sqrt(sum_sq);
                            int edge_count = (abs(i) == l) + (abs(j) == l) + (abs(k) == l);
                            double ratio = 1.0 / (1 << edge_count);
                            a += -1 * ratio * R / r;   // 依次计算c60与k1的作用势能
                            // flag = convertflag_k(x++); // 由晶体结构可知相邻点的电荷相反,故循环每进一步,flag进行变化
                        }
                    }
                }
                // 计算与k1,c的作用能
                for (i = -l + 1; i <= l - 1; i += 2) // 因为起始位c60与k1面,故下一部分为k2面
                {
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            r = sqrt(sum_sq);
                            flag = convertflag_k(x++);
                            a += -flag * R / r; // k2面肯定不是边缘,故无需权重
                        }
                    }
                }
            }
            else // 起始面为k1与C60
            {
                for (i = -l; i <= l; i += 2) // 计算K1与C60相互作用
                {
                    n1 = i;
                    for (j = -l; j <= l; j += 2)
                    {
                        n2 = j;
                        for (k = -l; k <= l; k += 2)
                        {
                            n3 = k;
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            r = sqrt(sum_sq);
                            int edge_count = (abs(i) == l) + (abs(j) == l) + (abs(k) == l);
                            double ratio = 1.0 / (1 << edge_count);
                            flag = convertflag_k(x++);
                            a += -flag * ratio * R / r; // 同理
                        }
                    }
                }
                /* 计算与k2相互作用 */
                for (i = -l + 1; i <= l - 1; i += 2)
                {
                    n1 = i;
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        n2 = j;
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            n3 = k;
                            double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                            if (sum_sq==0)
                            {
                                continue;
                            }
                            r = sqrt(sum_sq);
                            a += -1 * R / r;
                        }
                    }
                }
            }

            a_array.push_back(a);                     // 存放每一次循环结果
            cout << "m=" << m << "\ta=" << a << endl; // 输出m,a

            if (cnt % 4 == 0) // 每四次求一次均值
            {
                double sum = accumulate(a_array.end() - 4, a_array.end(), 0.0);
                aver = sum / 4.0;
                average.push_back(aver); // 将每个均值记录
                cout << "K2 result's average = " << setprecision(10) << aver << endl;
            }
        }

        cout << endl;
        if (!a_array.empty()) // 将最后八个均值求平均
        {
            double sum = accumulate(average.end() - 8, average.end(), 0.0);
            aver = sum / 8;
            cout << "K2 final result = " << aver << endl;
        }
        return aver;
        cout << endl;
    }
};

int main()
{
    K3C60 k1, c60, k2;
    int n1,n2,n3;
    printf("please enter the width for K1 culculation(n1):");
    cin >> n1;
    cout<<endl;
    printf("please enter the width for C60 culculation(n2):");
    cin >> n2;
    cout<<endl;
    printf("please enter the width for K2 culculation(n3):");
    cin >> n3;
    cout<<endl;
    int temp=(max(max(n1,n2),n3));
    n_num = cul_n(temp);

    cout << "K1:\n";
    double k1_final= k1.result_k1(n1);

    cout << "C60:\n";
    double C60_final= c60.result_c60(n2);

    cout << "K2:\n";
    double K2_final= k2.result_k2(n3);
    cout<<endl;
    cout<<endl;

    cout<<"K1_final="<<k1_final<<"\t"<<"C60_final="<<C60_final<<"\t"<<"K2_final="<<K2_final<<endl;
    system("pause");
    return 0;
}
