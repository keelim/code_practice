#include <vector>

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(vector<int> &intVector)
{
    if (intVector.size() < 2)
    {
     return {}; //empty vector
    }

    // we make an array with the length of the input array to
    // hold our products
    vector<int> productsOfAllIntsExceptAtIndex(intVector.size());

    // for each integer, we find the product of all the integers
    // before it, storing the total product so far each time
    int productSoFar = 1;
    for (size_t i = 0; i < intVector.size(); ++i)
    {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= intVector[i];
    }

    // for each integer, we find the product of all the integers
    // after it. since each index in products already has the
    // product of all the integers before it, now we're storing
    // the total product of all other integers
    productSoFar = 1;
    for (size_t i = intVector.size(); i > 0; --i)
    {
        size_t j = i - 1;
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= intVector[j];
    }

    return productsOfAllIntsExceptAtIndex;
}