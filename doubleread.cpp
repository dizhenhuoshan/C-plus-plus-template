double to_number(char *ch)
{
    double a = 0;
    int i = 0;
    bool flag = false;
    if (ch[0] == '-')
    {
        flag = true;
        i++;
    }
    while (ch[i] != '.' && ch[i] != '\0')
    {
        a += a * 10 + ch[i] - '0';
        i++;
    }
    if (ch[i] == '.')
    {
        i++;
        double k = 0.1;
        while (ch[i] != '\0')
        {
            a += (ch[i] - '0') * k;
            k *= 0.1;
            i++;
        }
    }
    if (flag)   return -a;
    else return a;
}
