//
// Created by hzl on 2020/9/2.
//
#include <include/cplusplus.h>

class Solution
{
    enum
    {
        None,
        Fuhao,
        Zhengshu,
        XiaoFuhao,
        Xiaoshu,
        EFuhao,
        EFuhao2,
        EShu,
    };

  public:
    bool isNumber(string s)
    {
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        auto status = None;

        bool bShuzi = false;
        for (const auto& c : s)
        {
            if(status == None){
                if (c == '-' || c == '+'){
                    status = Fuhao;
                    continue;
                }
                if (c >= '0' && c <= '9'){
                    status = Zhengshu;
                    bShuzi = true;
                    continue;
                }
                if (c == '.'){
                    status = XiaoFuhao;
                    continue;
                }
                return false;
            }

            if (status == Fuhao){
                if (c >= '0' && c <= '9'){
                    status = Zhengshu;
                    bShuzi = true;
                    continue;
                }
                if (c == '.'){
                    status = XiaoFuhao;
                    continue;
                }
                return false;
            }

            if (status == Zhengshu){
                if (c >= '0' && c <= '9'){
                    status = Zhengshu;
                    bShuzi = true;
                    continue;
                }
                if (c == '.'){
                    status = XiaoFuhao;
                    continue;
                }
                if (c == 'e' || c == 'E'){
                    status = EFuhao;
                    continue;
                }
                return false;
            }

            if(status == XiaoFuhao || status == Xiaoshu){
                if (c >= '0' && c <= '9'){
                    status = Xiaoshu;
                    bShuzi = true;
                    continue;
                }
                if (c == 'e' || c == 'E'){

                    if (status == XiaoFuhao && bShuzi == false){
                        return false;
                    }

                    status = EFuhao;
                    continue;
                }
                return false;
            }

            if (status == EFuhao){
                if (c == '+' || c =='-'){
                    status = EFuhao2;
                    continue;
                }
            }

            if (status == EFuhao || status == EFuhao2 || status == EShu){
                if (c >= '0' && c <= '9'){
                    status = EShu;
                    continue;
                }
                return false;
            }
        }
        return status == Zhengshu || status == Xiaoshu || status == EShu || (status == XiaoFuhao && bShuzi);
    }
};

int32_t main()
{
    string s;
    Solution solution;
    while (cin >> s){
        std::cout << solution.isNumber(s) << std::endl;
    }
    return 0;
}