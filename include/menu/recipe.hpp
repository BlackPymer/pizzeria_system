#pragma once
#include "menu/ingredient.hpp"
#include <map>
#include <memory>
#include <string>

class Recipe
{
public:
    Recipe(std::string name, int portions, int prep_time_seconds, bool is_vegetarian = false);
    void AddIngredient(std::shared_ptr<Ingredient> ingredient, int amount);
    int GetPortions() const;
    int GetPrepTimeSeconds() const;
    double GetCostPerPortion() const;
    int GetCaloriesPerPortion() const;
    bool IsVegetarian() const;
    void SetVegetarian(bool vegetarian);
    const std::map<std::shared_ptr<Ingredient>, int> &GetIngredients() const;

private:
    std::string _name;
    int _portions;
    int _prep_time_seconds;
    bool _is_vegetarian;
    std::map<std::shared_ptr<Ingredient>, int> _ingredients;
};