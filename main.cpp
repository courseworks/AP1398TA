#include <iostream>
#include <vector>

size_t findMin(std::vector<size_t> t);
size_t findArgmin(std::vector<size_t> t);
void findMinimum(std::vector<size_t> t, size_t& min, size_t& argmin);
size_t factorial(size_t n);
size_t factorial1(size_t n);
size_t fibo(size_t n);
size_t fibo1(size_t, std::vector<size_t>&);
size_t findMinOps(size_t i, size_t j, std::vector<size_t> p, std::vector<std::vector<size_t>>& m);

int main(){
    std::vector<size_t> p {5, 2, 10, 8, 8, 10, 90, 21, 12};
    std::vector<std::vector<size_t>> m;
    for (size_t i = 0; i < p.size(); i++)
        m.push_back(std::vector<size_t> (p.size(), 0));
    std::cout<<findMinOps(1, p.size()-1, p, m)<<std::endl;

    std::vector<size_t> u{1,2};
    u.push_back(5);
    std::cout<<"YEaaay"<<u[2]<<std::endl;
    u.pop_back();
    std::cout<<"YEaaay"<<u[2]<<std::endl;
    
}

size_t findMin(std::vector<size_t> t){
    size_t min{t[0]};
    for (size_t i = 1; i < t.size(); i++)
    {
        if (t[i] < min)
            min = t[i];
    }
    return min;
}

size_t findArgmin(std::vector<size_t> t){
    size_t min{};
    for (size_t i = 0; i < t.size(); i++)
    {
        if (t[i] < min)
            min = i;
    }
    return min;
}

void findMinimum(std::vector<size_t> t, size_t& m, size_t& a){
    m = t[0];
    a = 0;
    for (size_t i = 1; i < t.size(); i++)
    {
        if (t[i] < m){
            m = t[i];
            a = i;
            }
    }
}

size_t factorial(size_t n){
    size_t r{1};
    for (size_t i = 1; i < n+1; r*=i++);
    return r;
    
}

size_t factorial1(size_t n){
    if (n==1)
        return 1;
    return n * factorial1(n-1);
}

size_t fibo(size_t n){
    if (n==1 || n==2)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

size_t fibo1(size_t n, std::vector<size_t> &w){
    if (w.size() > n-1)
        return w[n-1];
    size_t temp{};
    temp = fibo1(n-1, w) + fibo1(n-2, w);
    w.push_back(temp);
    return temp;
}

size_t findMinOps(size_t i, size_t j, std::vector<size_t> p, std::vector<std::vector<size_t>>& m){
    if (i==j)
        return 0;
    if (m[i][j] != 0)
        return m[i][j];
    
    std::vector<size_t> temp{};
    
    for (size_t k = i; k < j; k++)
    {
        temp.push_back(findMinOps(i, k, p, m) + findMinOps(k+1, j, p, m) + p[i-1]*p[k]*p[j]);
    }
    size_t min{}, argmin{};
    findMinimum(temp, min, argmin);
    m[i][j] = min;
    return min;
}