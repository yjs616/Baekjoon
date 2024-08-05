#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int h, w, n, r, c, sh = 0, sw = 0, ret = -1, area1 = 0, area2 = 0;
bool isSuccess = false;
vector<pair<int, int>> v;

// 가로끼리 더함 세로 최대
bool check1(int r, int c)
{
    int maxH = max(sh, r);
    if (maxH > h || sw + c > w)
        return false;
    return true;
}
// 세로끼리 더함 가로 최대
bool check2(int r, int c)
{
    int maxW = max(sw, c);
    if (sh + r > h || maxW > w)
        return false;
    return true;
}

void reverse(int &r, int &c)
{
    int tmp = r;
    r = c;
    c = tmp;
}

int main()
{
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        v.push_back({r, c});
    }

    int k=1;
    while (k >= 0)
    {
        // 조합 이용(2개 뽑기)
        for (int i = 0; i < n; i++)
        {
            sh = v[i].first;
            sw = v[i].second;
            if(k==0) reverse(sh, sw);
            area1 = sh * sw;
            // cout << "area1 : " << area1 << "\n";

            for (int j = i + 1; j < n; j++)
            {
                int tmp_h = v[j].first;
                int tmp_w = v[j].second;
                area2 = tmp_h * tmp_w;
                // cout << "area2 : " <<area2 <<"\n";

                if (check1(tmp_h, tmp_w) || check2(tmp_h, tmp_w))
                {
                    ret = max(ret, area1 + area2);
                }
                else
                {
                    // 뒤집어서 확인
                    reverse(tmp_h, tmp_w);
                    // cout << "현재 tmp_h : " << tmp_h << " tmp_w : " <<tmp_w << "\n";
                    if (check1(tmp_h, tmp_w) || check2(tmp_h, tmp_w))
                    {
                        ret = max(ret, area1 + area2);
                    }
                }
            }
        }
        k--;
        
    }

    if (ret == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << ret << "\n";
    }
    return 0;
}