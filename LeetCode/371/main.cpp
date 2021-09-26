int getSum(int a, int b)
{
    int ret = 0;
    int t = 0;
    for (int i = 0; i < 32; i++)
    {
        int x = 1 & (a >> i);
        int y = 1 & (b >> i);
        if (x == 1 && y == 1)
        {
            if (t)
            {
                ret = ret | (1 << i);
            }
            t = 1;
        }
        else if (x == 1 || y == 1)
        {
            if (!t)
            {
                ret = ret | (1 << i);
            }
        }
        else
        {
            if (t)
            {
                ret = ret | (1 << i);
            }
            t = 0;
        }
    }

    return ret;
}