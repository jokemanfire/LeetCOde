#include"global.h"

class Solution {
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand(time(nullptr));
    }

    vector<int> flip() {
        int x = rand() % total;
        vector<int> ans;
        total--;
        // ����λ�� x ��Ӧ��ӳ��
        if (map.count(x)) {
            ans = { map[x] / n, map[x] % n };
        }
        else {
            ans = { x / n, x % n };
        }
        // ��λ�� x ��Ӧ��ӳ������Ϊλ�� total ��Ӧ��ӳ��
        if (map.count(total)) {
            map[x] = map[total];
        }
        else {
            map[x] = total;
        }
        return ans;
    }

    void reset() {
        total = m * n;
        map.clear();
    }
private:
    int m;
    int n;
    int total;
    unordered_map<int, int> map;
};


int main()
{
   Solution a = Solution(4,1);
   vector<int> c = a.flip();
   a.reset();
   c = a.flip();
   getchar();
}