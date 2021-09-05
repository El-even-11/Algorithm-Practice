int rand7()
{
    return 0;
}

int rand10()
{
    int random;
    while (true)
    {
        random = (rand7() - 1) * 7 + rand7() - 1;
        if (random < 40)
        {
            return random % 10 + 1;
        }
    }
    return 0;
}