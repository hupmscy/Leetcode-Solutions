class Solution {
public:
    char out[1000];
    int pos;

    void process(char a, char b, char c, int ind)
    {
        switch(ind)
        {
            case 1: out[pos++] = a;return;
            case 2: out[pos++] = a; out[pos++] = a; return;
            case 3: out[pos++] = a; out[pos++] = a; out[pos++] = a; return;
            case 4: out[pos++] = a; out[pos++] = b; return;
            case 5: out[pos++] = b; return;
            case 6: out[pos++] = b; out[pos++] = a;return;
            case 7: out[pos++] = b; out[pos++] = a; out[pos++] = a; return;
            case 8: out[pos++] = b; out[pos++] = a; out[pos++] = a; out[pos++] = a; return;
            case 9: out[pos++] = a; out[pos++] = c; return;
        }
    }

    string intToRoman(int num) {

        pos = 0;
        while (num)
        {
            if (num >= 1000)
            {
                num-=1000;
                out[pos++] = 'M';
            }
            else if (num >= 100)
            {
                char a = 'C';
                char b = 'D';
                char c = 'M';
                process(a, b, c, num/100);
                num -= num/100*100;
            }
            else if (num >= 10)
            {
                char a = 'X';
                char b = 'L';
                char c = 'C';
                process(a, b, c, num/10);
                num -= num/10*10;
            }
            else
            {
                char a = 'I';
                char b = 'V';
                char c = 'X';
                process(a, b, c, num);
                num -= num;
            }
        }
        out[pos] = 0;
        return string(out);
    }
};
