#include "IRecipe.h"

bool operator<(const IRecipe& lhs, const IRecipe& rhs){
    return (lhs.getvalue() < rhs.getvalue());
}

bool operator==(const IRecipe& lhs, const IRecipe & rhs){
    return (lhs.getvalue() == rhs.getvalue());
}
