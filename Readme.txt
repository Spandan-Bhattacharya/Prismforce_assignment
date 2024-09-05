The given solution takes input the following parameters from the user to the function fightAbhimanyu:
int n = number of rings in the Chakravyuha
vector<int> powers = powers of the kth enemy in the kth ring
vector<bool> special = 1 if the ith enemy can regenerate and atack in the next ring, else 0
int p = initial strength of Abhimanyu
int a = number of skips
int b = number of regenerations

Input format:
//n
//Elements of power, each separated by a single space
//Elements of special, each separated by a single space
//values of p, a, b, each separted by a single space

Constraints assumed:
n = 11
0 <= powers[i] <= 100
3rd and 7th enemy has special powers
For halfing the health of the enemy, the half value is rounded down to the nearest integer
0 <= p <= 100
0 <= a <= 10
0 <= b <= 10
