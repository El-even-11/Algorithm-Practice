#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
using namespace std;

// population size
const int size = 20;

const int generation = 50;

// mutation probability
const double mutation_p = 0.05;

// crossover probability
const double crossover_p = 0.2;

int individuals[size] = {0};
double fitnesses[size];

// probability of being selected
double probability[size];
double probability_interval[size + 1] = {0};

// best fitness of each generation
int best_individuals[generation + 1];
double best_fitnesses[generation + 1];

default_random_engine e(time(0));

// decode individual into a specific number in [-1,15]
double decode(int individual)
{
    return -1 + 16.0 / 65535.0 * individual;
}

// print individual in binary form
void print_in_binary(int individual)
{
    for (int i = 15; i >= 0; i--)
    {
        cout << ((individual >> i) & 1);
    }
    cout << endl;
}

// target function : x*sin(x)
double f(int individual)
{
    double x = decode(individual);
    return x * sin(x);
}

// obtain individual randomly with fitness as weight
int weighted_random_get_individual()
{
    uniform_real_distribution<double> u(0, 1);
    double x = u(e);
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (x >= probability_interval[i] && x <= probability_interval[i + 1])
        {
            index = i;
            break;
        }
    }
    return individuals[index];
}

// individual index
int weighted_random_get_individual_idx()
{
    uniform_real_distribution<double> u(0, 1);
    double x = u(e);
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (x >= probability_interval[i] && x <= probability_interval[i + 1])
        {
            index = i;
            break;
        }
    }
    return index;
}

void initialize()
{
    uniform_int_distribution<int> u(0, 65535);
    for (int i = 0; i < size; i++)
    {
        individuals[i] = u(e);
    }
    for (int i = 0; i < size; i++)
    {
        fitnesses[i] = f(individuals[i]);
        fitnesses[i] = 30 - fitnesses[i];
    }
}

void selection()
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += fitnesses[i];
    }

    for (int i = 0; i < size; i++)
    {
        probability[i] = fitnesses[i] / sum;
    }

    for (int i = 0; i < size; i++)
    {
        probability_interval[i + 1] = probability_interval[i] + probability[i];
    }

    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = weighted_random_get_individual();
    }

    for (int i = 0; i < size; i++)
    {
        individuals[i] = temp[i];
    }

    for (int i = 0; i < size; i++)
    {
        fitnesses[i] = f(individuals[i]);
        fitnesses[i] = 30 - fitnesses[i];
    }
}

void crossover()
{
    uniform_real_distribution<double> u_r(0, 1);
    uniform_int_distribution<int> u_i(0, size - 1);

    if (u_r(e) > crossover_p)
    {
        // do not crossover
        return;
    }
    int fa_idx = weighted_random_get_individual_idx();
    int mo_idx = weighted_random_get_individual_idx();

    int cross_idx = u_i(e);

    int fa_digit = (individuals[fa_idx] >> cross_idx) & 1;
    int mo_digit = (individuals[mo_idx] >> cross_idx) & 1;

    if (fa_digit)
    {
        individuals[mo_digit] |= (1 << cross_idx);
    }
    else
    {
        individuals[mo_digit] &= ~(1 << cross_idx);
    }

    if (mo_digit)
    {
        individuals[fa_digit] |= (1 << cross_idx);
    }
    else
    {
        individuals[fa_digit] &= ~(1 << cross_idx);
    }
}

void mutation()
{
    uniform_real_distribution<double> u(0, 1);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (u(e) > mutation_p)
            {
                // do not mutate
                continue;
            }
            individuals[i] ^= (1 << j);
        }
    }
}

int get_best_idx()
{
    int max_idx = -1;
    double max = -1;
    for (int i = 0; i < size; i++)
    {
        if (fitnesses[i] > max)
        {
            max = fitnesses[i];
            max_idx = i;
        }
    }
    return max_idx;
}

void get_best(int generation)
{
    int best_idx = get_best_idx();
    best_individuals[generation] = individuals[best_idx];
    best_fitnesses[generation] = fitnesses[best_idx];
    cout << "generation " << generation << " \t:" << decode(best_individuals[generation]) << "  \t" << best_fitnesses[generation] << endl;
}

int main()
{
    initialize();

    // iterate through generations
    for (int i = 1; i <= generation; i++)
    {
        selection();
        get_best(i);
        crossover();
        mutation();
    }
    cout << endl;

    // find global best result of all generations
    double max = -1;
    int best_generation = -1;
    for (int i = 0; i < generation; i++)
    {
        if (best_fitnesses[i] > max)
        {
            max = best_fitnesses[i];
            best_generation = i;
        }
    }

    cout << "global best result" << endl;
    cout << "generation : " << best_generation << endl;
    cout << "individual : ";
    print_in_binary(best_individuals[best_generation]);
    cout << "result : " << decode(best_individuals[best_generation]) << endl;

    return 0;
}
