// 字符串匹配 - BM 算法

// 坏字符
void PreBMBc(string &pattern, int m, int bmBc[])
{
    int i;
    for (i = 0; i < 256; ++i) {
        bmBc[i] = m;
    }
    for (i = 0; i < m - 1; ++i) {
        bmBc[pattern[i]] = m - 1 - i;
    }
}

// 好后缀
// 求pattern中以i位置字符为后缀和以最后一个字符为后缀的公共后缀串的长度
void suffix(string &pattern, int m, int suff[])
{
    int i, j;
    int k = 0;
    suff[m - 1] = m;
    j = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > j && suff[i + m - 1 - k] < i - j) {
            suff[i] = suff[i + m - 1 - k];
        } else {
            if (i < j) {
                j = i;
            }
            k = i;
            while (j >= 0 && pattern[j] == pattern[j + m - 1 - k]) {
                --j;
            }
            suff[i] = k - j;
        }
    }
}

void PreBMGs(string &pattern, int m, int bmGs[])
{
    int i;
    int suff[256];
    suffix(pattern, m, suff);

    for (i = 0; i < m; ++i) {
        bmGs[i] = m;
    }

    int j = 0;
    for (i = m -1; i >= 0; --i) {
        if (suff[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (bmGs[j] == m) {
                    bmGs[j] = m - 1 - i;
                }
            }
        }
    }

    for (i = 0; i <= m - 2; ++i) {
        bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
}
void BM(string &pattern, int m, string &text, int n)
{
    int i;
    int bmBc[256];
    int bmGs[256];

    PreBMBc(pattern, m, bmBc);
    PreBMGs(pattern, m, bmGs);

    int j = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; --i);
        if (i < 0) {
            cout << "match: " << j << endl;
            j += bmGs[0];
            return;
        } else {
            j += MAX(bmBc[text[i + j]] - m + 1 + i, bmGs[i]);
        }
    }
    cout << "NOt found";
}