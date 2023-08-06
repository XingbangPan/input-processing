using namespace std;
#include <iostream>
#include "vector"
#include "algorithm"

/*
Solution1表示单行输入处理策略
Solution2表示多行输入处理策略
*/

class Solution1
{

public:
    // 1.1 数字以空格分隔开
    void func1()
    {
        int num;
        vector<int> result;

        while (1)
        {
            cin >> num;
            result.push_back(num);
            char ch = getchar();
            if (ch == '\n')
                break;
        }

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 1.2 数字不以空格分隔开，将每一位`0~9`的数字分割开
    //  从低位到高位分割
    void func2()
    {

        int num;
        cin >> num;

        vector<int> result;

        while (1)
        {

            if (num == 0)
                break;

            int cur = num % 10;
            num = num / 10;

            result.push_back(cur);
        }

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 1.2 数字不以空格分隔开，将每一位`0~9`的数字分割开
    //  从高位到低位分割
    void func3Helper(int num, vector<int> &result)
    {
        // 递归终止条件
        if (num == 0)
            return;

        // 单层递归逻辑
        int cur = num % 10;
        num = num / 10;

        func3Helper(num, result);

        result.push_back(cur);
    }

    void func3()
    {
        int num;
        cin >> num;

        vector<int> result;

        func3Helper(num, result);

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 2.1 字符以空格分隔开
    void func4()
    {
        char c;
        string result;
        while (1)
        {
            cin >> c;
            result.push_back(c);
            if (getchar() == '\n')
                break;
        }
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 2.2 字符不以空格分隔开，将每一位字符分隔开
    void func5()
    {
        string result;
        cin >> result;
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 3.1 字符串以空格分隔开
    void func6()
    {
        string str;
        vector<string> result;
        while (1)
        {
            cin >> str;
            result.push_back(str);
            if (getchar() == '\n')
                break;
        }

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 3.2 字符串不以空格分隔开，以给定的特殊字符分隔开(例如'#')
    void func7()
    {
        string str;
        getline(cin, str);

        vector<string> result;

        // 双指针
        int left, right = 0;
        while (1)
        {
            // 找尾
            if (str.find('#', left) == str.npos)
            {
                result.push_back(str.substr(left));
                break;
            }
            right = str.find('#', left);

            result.push_back(str.substr(left, right - left));

            // 找头
            left = right + 1;
        }

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // 3.2 字符串不以空格分隔开，以给定的特殊字符分隔开(例如'#')
    // 读取带空格的字符串
    void func8()
    {
        string str;
        getline(cin, str);
        cout << str;
    }
};

class Solution2
{
#define N 3
public:
    // 读取给定行
    // 1. 单行策略不同
    void func1()
    {
        string level1;
        vector<int> level2;
        string level3;

        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                cin >> level1;
            }
            else if (i == 1)
            {
                int num;
                cin >> num;
                while (1)
                {
                    if (num == 0)
                        break;
                    int cur = num % 10;
                    num = num / 10;
                    level2.push_back(cur);
                }
                reverse(level2.begin(), level2.end());
            }
            else
            {
                cin >> level3;
            }
        }

        for (auto i : level1)
        {
            cout << i << " ";
        }
        cout << endl;

        for (auto i : level2)
        {
            cout << i << " ";
        }
        cout << endl;

        for (auto i : level3)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 读取给定行
    // 2. 单行策略相同
    void func2()
    {
        vector<vector<int>> result;
        for (int i = 0; i < N; i++)
        {
            vector<int> level;
            while (1)
            {
                int num;
                cin >> num;
                level.push_back(num);
                if (getchar() == '\n')
                    break;
            }
            result.push_back(level);
        }

        for (auto i : result)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 读取未知行，以特定数字或字符或字符串为结束条件
    // 1. 单行策略不同
    //  假设每四行为一段，第一行为一个数字，第二行以空格分隔的数字，第三行为以空格分隔的字符，第四行为以空格分隔的字符串
    //  当某一段的第一行读取到数字0时，输入结束
    void func3()
    {
        int level1;
        vector<int> level2;
        string level3;
        vector<string> level4;

        while (1)
        {
            cin >> level1;
            if (level1 == 0)
                break;

            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    while (1)
                    {
                        int num;
                        cin >> num;
                        level2.push_back(num);
                        if (getchar() == '\n')
                            break;
                    }
                }
                else if (i == 1)
                {
                    while (1)
                    {
                        char c;
                        cin >> c;
                        level3.push_back(c);
                        if (getchar() == '\n')
                            break;
                    }
                }
                else
                {
                    while (1)
                    {
                        string str;
                        cin >> str;
                        level4.push_back(str);
                        if (getchar() == '\n')
                            break;
                    }
                }
            }
        }

        for (auto i : level2)
        {
            cout << i << " ";
        }
        cout << endl;

        for (auto i : level3)
        {
            cout << i << " ";
        }
        cout << endl;

        for (auto i : level4)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 读取未知行，以特定数字或字符或字符串为结束条件
    //  2. 单行策略相同
    void func4()
    {
        vector<string> result;
        while (1)
        {
            string level;
            cin >> level;
            if (level == "stop")
                break;
            result.push_back(level);
        }

        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
