// Shopping Cart system
/*  Rules
 1. Same product should not appear twice
 2. Quantity update instead of duplicate insertion
 3. Removing zero quantity auto-deletes item
 4. Adding from store decreases store quantity
 5. Removing from cart increases store quantity */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <limits>
#include <iomanip>

struct Item {
  std::string name;
  int quantity;
  double price;
};

std::string to_lower(std::string s) {
  for (char& c : s) {
    c = std::tolower(static_cast<unsigned char>(c));
  }
  return s;
}

void item_add(std::vector<Item>& y) {
  
  int n;
  std::cout << "How many products you want to enter?\n";
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  for(int i = 0; i < n; i++) {
    std::string add_name;
    int add_quantity;
    double add_price;
    
    std::cout << "Enter product " << i+1 << " name : "; 
    std::getline(std::cin, add_name);
    add_name = to_lower(add_name);
    
    std::cout << "Enter product " << i+1 << " quantity : ";
    std::cin >> add_quantity;
    
    std::cout << "Enter product " << i+1 << " price : ";
    std::cin >> add_price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Check if product already exists (Rule 1: Same product should not appear twice)
    auto it = std::find_if(y.begin(), y.end(),
                           [&](const Item& item) {
                             return item.name == add_name;
                           });
    
    if (it != y.end()) {
      // Rule 2: Quantity update instead of duplicate insertion
      it->quantity += add_quantity;
      std::cout << "Product already exists. Quantity updated.\n";
    } else {
      Item temp;
      temp.name = add_name;
      temp.quantity = add_quantity;
      temp.price = add_price;
      
      y.push_back(temp);
    }
  }
  std::cout << "All products are added successfully.\n";
  
}

void item_remove(std::vector<Item>& y) {
  
  int m;
  std::cout << "How many products you want to remove?\n";
  std::cin >> m;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  for (int i = 0; i < m; i++) {
    std::string rm_name;
    int rm_quantity;
    
    std::cout << "Enter product " << i + 1 << " name : ";
    std::getline(std::cin, rm_name);
    rm_name = to_lower(rm_name);
    
    // find item by name
    auto it = std::find_if(y.begin(), y.end(),
                           [&](const Item& item) {
                             return item.name == rm_name;
                           });
    
    if (it != y.end()) {
      std::cout << "Enter product " << i + 1 << " quantity to remove : ";
      std::cin >> rm_quantity;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
      if (it->quantity > rm_quantity) {
        it->quantity -= rm_quantity;
      }
      else if (it->quantity == rm_quantity) {
        // Rule 3: Removing zero quantity auto-deletes item
        y.erase(it);
        std::cout << "Product removed completely.\n";
      }
      else {
        std::cout << "That much item is not available to remove.\n";
      }
    }
    else {
      std::cout << "Product not found.\n";
    }
  }
  
  std::cout << "Remove operation completed.\n";
}

void item_display(std::vector<Item>& y) {
  if (y.empty()) {
    std::cout << "No products available.\n";
    return;
  }
  
  std::cout << "\nAvailable products in store:\n";
  std::cout << "------------------------------------------------------------\n";
  std::cout << "No  Product name              Quantity           Price (USD)\n";
  std::cout << "------------------------------------------------------------\n";
  
  int index = 1;
  for (const auto& it : y) {
    std::cout << index++ << "   "
              << std::left << std::setw(30) << it.name
              << it.quantity << "     $"
              << std::fixed << std::setprecision(2) << it.price << "\n";
  }
  std::cout << "------------------------------------------------------------\n";
}

void item_search(std::vector<Item>& y) {
  std::string search;
  
  std::cout << "Enter product name to search : ";
  std::getline(std::cin, search);
  search = to_lower(search);
  
  auto it = std::find_if(y.begin(), y.end(),
                         [&](const Item& item) {
                           return item.name == search;
                         });
  
  if(it != y.end()) {
    int index = it - y.begin();
    
    std::cout << "Item found at index :" << index << std::endl;
    std::cout << "name :          "  << it->name << std::endl
              << "quantity :      " << it->quantity << std::endl
              << "price (unit) :$ " << std::fixed << std::setprecision(2) << it->price << std::endl;
  }
  else {
    std::cout << "Item not found.\n";
  }
}

void update_quantity(std::vector<Item>& y) {
  std::string prod_name;
  int new_quantity;
  
  std::cout << "Enter product name to update : ";
  std::getline(std::cin, prod_name);
  prod_name = to_lower(prod_name);
  
  auto it = std::find_if(y.begin(), y.end(),
                         [&](const Item& item) {
                           return item.name == prod_name;
                         });
  
  if (it != y.end()) {
    std::cout << "Current quantity: " << it->quantity << "\n";
    std::cout << "Enter new quantity: ";
    std::cin >> new_quantity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (new_quantity > 0) {
      it->quantity = new_quantity;
      std::cout << "Quantity updated successfully.\n";
    } else if (new_quantity == 0) {
      y.erase(it);
      std::cout << "Product removed (quantity set to zero).\n";
    } else {
      std::cout << "Invalid quantity entered.\n";
    }
  } else {
    std::cout << "Product not found.\n";
  }
}

// Update quantity in cart WITH STORE SYNC - FIXED VERSION
void update_quantity_in_cart(std::vector<Item>& cart, std::vector<Item>& store) {
  if (cart.empty()) {
    std::cout << "Cart is empty. Nothing to update.\n";
    return;
  }
  
  std::string prod_name;
  int new_quantity;
  
  std::cout << "Enter product name to update : ";
  std::getline(std::cin, prod_name);
  prod_name = to_lower(prod_name);
  
  // Find item in cart using index
  int cart_index = -1;
  for (int i = 0; i < cart.size(); i++) {
    if (cart[i].name == prod_name) {
      cart_index = i;
      break;
    }
  }
  
  if (cart_index == -1) {
    std::cout << "Product not found in cart.\n";
    return;
  }
  
  int old_quantity = cart[cart_index].quantity;
  std::cout << "Current quantity in cart: " << old_quantity << "\n";
  std::cout << "Enter new quantity: ";
  std::cin >> new_quantity;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  if (new_quantity <= 0) {
    std::cout << "Invalid quantity entered.\n";
    return;
  }
  
  // Find item in store
  int store_index = -1;
  for (int i = 0; i < store.size(); i++) {
    if (store[i].name == prod_name) {
      store_index = i;
      break;
    }
  }
  
  // Calculate difference
  int quantity_difference = new_quantity - old_quantity;
  
  if (quantity_difference > 0) {
    // Increasing cart quantity - need to take from store
    if (store_index == -1 || store[store_index].quantity < quantity_difference) {
      int available = (store_index != -1) ? store[store_index].quantity : 0;
      std::cout << "Sorry! Only " << available << " items available in store.\n";
      return;
    }
    
    // Update quantities
    cart[cart_index].quantity = new_quantity;
    store[store_index].quantity -= quantity_difference;
    
    // Remove from store if quantity becomes 0
    if (store[store_index].quantity == 0) {
      store.erase(store.begin() + store_index);
      std::cout << "Quantity updated. Product out of stock in store.\n";
    } else {
      std::cout << "Quantity updated. Removed " << quantity_difference << " from store.\n";
      std::cout << "Remaining in store: " << store[store_index].quantity << "\n";
    }
  } else {
    // Decreasing cart quantity - return to store
    int quantity_to_return = -quantity_difference;
    cart[cart_index].quantity = new_quantity;
    
    if (store_index != -1) {
      store[store_index].quantity += quantity_to_return;
    } else {
      // Product doesn't exist in store, add it back
      Item returned_item;
      returned_item.name = prod_name;
      returned_item.quantity = quantity_to_return;
      returned_item.price = cart[cart_index].price;
      store.push_back(returned_item);
      std::sort(store.begin(), store.end(),
                [](const Item& a, const Item& b) {
                  return a.name < b.name;
                });
    }
    
    std::cout << "Quantity updated. Returned " << quantity_to_return << " to store.\n";
  }
  
  // Remove from cart if quantity becomes 0
  if (cart[cart_index].quantity == 0) {
    cart.erase(cart.begin() + cart_index);
    std::cout << "Product removed completely from cart.\n";
  }
}

// Add item from store to cart with quantity management
void add_to_cart(std::vector<Item>& store, std::vector<Item>& cart) {
  if (store.empty()) {
    std::cout << "Store is empty. No products available.\n";
    return;
  }
  
  std::cout << "\n========== Available Products in Store ==========\n";
  item_display(store);
  
  std::string prod_name;
  int cart_quantity;
  
  std::cout << "Enter product name to add to cart: ";
  std::getline(std::cin, prod_name);
  prod_name = to_lower(prod_name);
  
  // Find item in store using index
  int store_index = -1;
  for (int i = 0; i < store.size(); i++) {
    if (store[i].name == prod_name) {
      store_index = i;
      break;
    }
  }
  
  if (store_index == -1) {
    std::cout << "Product not found in store.\n";
    return;
  }
  
  std::cout << "Available quantity in store: " << store[store_index].quantity << "\n";
  std::cout << "Enter quantity to add to cart: ";
  std::cin >> cart_quantity;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  // Check if enough quantity available in store
  if (cart_quantity > store[store_index].quantity) {
    std::cout << "Sorry! Only " << store[store_index].quantity << " items available in store.\n";
    return;
  }
  
  if (cart_quantity <= 0) {
    std::cout << "Invalid quantity entered.\n";
    return;
  }
  
  // Find item in cart (if already exists)
  int cart_index = -1;
  for (int i = 0; i < cart.size(); i++) {
    if (cart[i].name == prod_name) {
      cart_index = i;
      break;
    }
  }
  
  if (cart_index != -1) {
    // Item already in cart, update quantity
    cart[cart_index].quantity += cart_quantity;
  } else {
    // New item, add to cart
    Item new_item;
    new_item.name = prod_name;
    new_item.quantity = cart_quantity;
    new_item.price = store[store_index].price;
    cart.push_back(new_item);
  }
  
  // Decrease store quantity
  store[store_index].quantity -= cart_quantity;
  
  // Rule 3: Auto-delete from store if quantity becomes 0
  if (store[store_index].quantity == 0) {
    store.erase(store.begin() + store_index);
    std::cout << cart_quantity << " " << prod_name << "(s) added to cart. Product out of stock in store.\n";
  } else {
    std::cout << cart_quantity << " " << prod_name << "(s) added to cart successfully.\n";
    std::cout << "Remaining quantity in store: " << store[store_index].quantity << "\n";
  }
}

// Remove item from cart and return to store
void remove_from_cart(std::vector<Item>& store, std::vector<Item>& cart) {
  if (cart.empty()) {
    std::cout << "Cart is empty. Nothing to remove.\n";
    return;
  }
  
  std::cout << "\n========== Items in Your Cart ==========\n";
  item_display(cart);
  
  std::string prod_name;
  int remove_quantity;
  
  std::cout << "Enter product name to remove from cart: ";
  std::getline(std::cin, prod_name);
  prod_name = to_lower(prod_name);
  
  // Find item in cart using index
  int cart_index = -1;
  for (int i = 0; i < cart.size(); i++) {
    if (cart[i].name == prod_name) {
      cart_index = i;
      break;
    }
  }
  
  if (cart_index == -1) {
    std::cout << "Product not found in cart.\n";
    return;
  }
  
  std::cout << "Quantity in cart: " << cart[cart_index].quantity << "\n";
  std::cout << "Enter quantity to remove from cart: ";
  std::cin >> remove_quantity;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  if (remove_quantity > cart[cart_index].quantity) {
    std::cout << "You only have " << cart[cart_index].quantity << " items in cart.\n";
    return;
  }
  
  if (remove_quantity <= 0) {
    std::cout << "Invalid quantity entered.\n";
    return;
  }
  
  double product_price = cart[cart_index].price;
  std::string product_name = cart[cart_index].name;
  
  if (cart[cart_index].quantity > remove_quantity) {
    // Partial removal
    cart[cart_index].quantity -= remove_quantity;
  } else {
    // Complete removal
    cart.erase(cart.begin() + cart_index);
    std::cout << "Product removed completely from cart.\n";
  }
  
  // Return to store - find if product exists in store using index
  int store_index = -1;
  for (int i = 0; i < store.size(); i++) {
    if (store[i].name == product_name) {
      store_index = i;
      break;
    }
  }
  
  if (store_index != -1) {
    // Product exists in store, increase quantity
    store[store_index].quantity += remove_quantity;
  } else {
    // Product doesn't exist in store, add it back
    Item returned_item;
    returned_item.name = product_name;
    returned_item.quantity = remove_quantity;
    returned_item.price = product_price;
    store.push_back(returned_item);
    std::sort(store.begin(), store.end(),
              [](const Item& a, const Item& b) {
                return a.name < b.name;
              });
  }
  
  std::cout << remove_quantity << " " << product_name << "(s) removed from cart and returned to store.\n";
  std::cout << "Current quantity in store: " << (store_index != -1 ? store[store_index].quantity : remove_quantity) << "\n";
}

double calculate_total(std::vector<Item>& y) {
  double total = 0.0;
  for (const auto& item : y) {
    total += item.quantity * item.price;
  }
  return total;
}

int calculate_total_items(std::vector<Item>& y) {
  int count = 0;
  for (const auto& item : y) {
    count += item.quantity;
  }
  return count;
}

void make_bill(std::vector<Item>& y) {
  if (y.empty()) {
    std::cout << "Cart is empty. Cannot generate bill.\n";
    return;
  }
  
  std::cout << "\n";
  std::cout << "=====================================================================\n";
  std::cout << "                          SHOPPING BILL\n";
  std::cout << "=====================================================================\n";
  std::cout << std::left << std::setw(25) << "Product Name" 
            << std::right << std::setw(10) << "Quantity" 
            << std::right << std::setw(12) << "Unit Price" 
            << std::right << std::setw(12) << "Total\n";
  std::cout << "---------------------------------------------------------------------\n";
  
  double grand_total = 0.0;
  
  for (const auto& item : y) {
    double item_total = item.quantity * item.price;
    grand_total += item_total;
    
    std::cout << std::left << std::setw(25) << item.name
              << std::right << std::setw(10) << item.quantity
              << std::right << std::setw(12) << "$" << std::fixed << std::setprecision(2) << item.price
              << std::right << std::setw(11) << "$" << std::fixed << std::setprecision(2) << item_total << "\n";
  }
  
  std::cout << "--------------------------------------------------------------------\n";
  std::cout << std::right << std::setw(48) << "Grand Total: $" << std::fixed << std::setprecision(2) << grand_total << "\n";
  std::cout << "=====================================================================\n\n";
}

void clear_cart(std::vector<Item>& cart, std::vector<Item>& store) {
  if (cart.empty()) {
    std::cout << "Cart is already empty.\n";
  } else {
    // Return all items from cart back to store
    for (const auto& item : cart) {
      int store_index = -1;
      for (int i = 0; i < store.size(); i++) {
        if (store[i].name == item.name) {
          store_index = i;
          break;
        }
      }
      
      if (store_index != -1) {
        store[store_index].quantity += item.quantity;
      } else {
        store.push_back(item);
      }
    }
    
    // Sort store after adding back items
    std::sort(store.begin(), store.end(),
              [](const Item& a, const Item& b) {
                return a.name < b.name;
              });
    
    cart.clear();
    std::cout << "Cart cleared successfully. All items returned to store.\n";
  }
}

int main() {
  
  int menu_choice, menu1_choice, menu2_choice, menu3_choice;
  std::vector<Item> c_items;
  
  std::cout << "\n=====================================\n";
  std::cout << "||********* Grocery Store *********||\n";
  std::cout << "=====================================\n";
  
  // shop's products' list. prices are in USD.
  std::vector<Item> s_items = {
    {"Rice", 10, 1.50},
    {"Wheat Flour", 10, 1.20},
    {"Sugar", 10, 1.10},
    {"Salt", 10, 0.60},
    {"Cooking Oil", 10, 3.50},
    
    {"Lentils", 10, 1.80},
    {"Chickpeas", 10, 1.90},
    {"Split Peas", 10, 1.70},
    {"Tea", 10, 2.50},
    {"Coffee", 10, 4.00},
    
    {"Milk", 10, 1.30},
    {"Yogurt", 10, 1.00},
    {"Butter", 10, 2.80},
    {"Cheese", 10, 3.20},
    {"Eggs", 10, 2.50},
    
    {"Bread", 10, 1.40},
    {"Biscuits", 10, 1.20},
    {"Instant Noodles", 10, 0.90},
    {"Pasta", 10, 1.60},
    {"Breakfast Cereal", 10, 3.80},
    
    {"Potatoes", 10, 0.80},
    {"Onions", 10, 0.70},
    {"Garlic", 10, 0.60},
    {"Ginger", 10, 0.90},
    {"Tomatoes", 10, 1.10},
    
    {"Apples", 10, 2.00},
    {"Bananas", 10, 1.20},
    {"Oranges", 10, 1.50},
    {"Mangoes", 10, 2.50},
    {"Grapes", 10, 2.80},
    
    {"Chicken", 10, 4.50},
    {"Beef", 10, 6.50},
    {"Fish", 10, 5.00},
    {"Frozen Nuggets", 10, 4.20},
    {"Sausages", 10, 3.80},
    
    {"Soap", 10, 0.90},
    {"Shampoo", 10, 3.00},
    {"Toothpaste", 10, 2.20},
    {"Toothbrush", 10, 1.00},
    {"Detergent", 10, 4.00},
    
    {"Dishwashing Liquid", 10, 2.50},
    {"Tissue Paper", 10, 1.80},
    {"Hand Sanitizer", 10, 1.50},
    {"Face Mask", 10, 0.70},
    {"Face wash", 10, 3.20},
    
    {"Chocolate", 10, 1.50},
    {"Chips", 10, 1.20},
    {"Ice Cream", 10, 2.80},
    {"Jam", 10, 2.40},
    {"Honey", 10, 3.50}
  };
  
  // lower case and sort alphabetically
  for(auto &it : s_items) {
    it.name = to_lower(it.name);
  }
  
  std::sort(s_items.begin(), s_items.end(),
            [](const Item& a, const Item& b){
              return a.name < b.name;
            });
  
  // menu loop
  while(true) {
    
    std::cout << "\n1. MENU 1 - Store's system \n";
    std::cout << "2. MENU 2 - Shopping cart \n";
    std::cout << "3. MENU 3 - Shopping bill \n";
    std::cout << "4. Exit\n";
    
    std::cout << "Enter choice: ";
    std::cin >> menu_choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if(menu_choice == 1) {
      while(true) {

        std::cout << "\n========== MENU 1 - Store's system ==========\n";
        std::cout << "1. Add product in store\n";
        std::cout << "2. Remove product in store\n";
        std::cout << "3. Display all product of the store\n";
        std::cout << "4. Search product in store\n";
        std::cout << "5. Update quantity\n";
        std::cout << "6. Exit\n";
        
        std::cout << "Enter choice: ";
        std::cin >> menu1_choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(menu1_choice == 1) {
          std::cout << "\n***** 1. Add product in store *****\n\n";
          item_add(s_items);
        }
        
        else if(menu1_choice == 2) {
          std::cout << "\n***** 2. Remove product in store *****\n\n";
          item_remove(s_items);
        }
        
        else if(menu1_choice == 3) {
          std::cout << "\n***** 3. Display all product of the store *****\n\n";
          item_display(s_items);
        }
        
        else if(menu1_choice == 4) {
          std::cout << "\n***** 4. Search product in store *****\n\n";
          item_search(s_items);
        }
        
        else if(menu1_choice == 5) {
          std::cout << "\n***** 5. Update quantity *****\n\n";
          update_quantity(s_items);
        }
        
        else if(menu1_choice == 6) {
          std::cout << "\n========== EXITING MENU - 1 ==========\n";
          break;
        }
        
        else {
          std::cout << "Invalid choice\n";
        }
      }
    } 
    else if(menu_choice == 2) {
      while(true) {

        std::cout << "\n========== MENU 2 - Shopping cart ==========\n";
        std::cout << "1. Add product to cart\n";
        std::cout << "2. Remove product from cart\n";
        std::cout << "3. Display all product in cart\n";
        std::cout << "4. Search product in cart\n";
        std::cout << "5. Update quantity in cart\n";
        std::cout << "6. Clear cart\n";
        std::cout << "7. Exit\n";
        
        std::cout << "Enter choice: ";
        std::cin >> menu2_choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(menu2_choice == 1) {
          std::cout << "\n***** 1. Add product to cart *****\n\n";
          add_to_cart(s_items, c_items);
        }
        
        else if(menu2_choice == 2) {
          std::cout << "\n***** 2. Remove product from cart *****\n\n";
          remove_from_cart(s_items, c_items);
        }
        
        else if(menu2_choice == 3) {
          std::cout << "\n***** 3. Display all product in cart *****\n\n";
          item_display(c_items);
        }
        
        else if(menu2_choice == 4) {
          std::cout << "\n***** 4. Search product in cart *****\n\n";
          item_search(c_items);
        }
        
        else if(menu2_choice == 5) {
          std::cout << "\n***** 5. Update quantity in cart *****\n\n";
          update_quantity_in_cart(c_items, s_items);
        }
        
        else if(menu2_choice == 6) {
          std::cout << "\n***** 6. Clear cart *****\n\n";
          clear_cart(c_items, s_items);
        }
        
        else if(menu2_choice == 7) {
          std::cout << "\n========== EXITING MENU - 2 ==========\n";
          break;
        }
        
        else {
          std::cout << "Invalid choice\n";
        }
      } 
   }
   
   else if(menu_choice == 3) {
    while(true) {
     
      std::cout << "\n========== MENU 3 - Shopping bill ==========\n";
      std::cout << "1. Calculate total items\n";
      std::cout << "2. Make bill\n";
      std::cout << "3. Exit\n";
      
      std::cout << "Enter choice: ";
      std::cin >> menu3_choice;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
      if(menu3_choice == 1) {
        int total_items = calculate_total_items(c_items);
        double total_price = calculate_total(c_items);
        
        std::cout << "\n========== CART SUMMARY ==========\n";
        std::cout << "Total items in cart: " << total_items << "\n";
        std::cout << "Total price: $" << std::fixed << std::setprecision(2) << total_price << "\n";
        std::cout << "==================================\n";
      }
      
      else if(menu3_choice == 2) {
        make_bill(c_items);
      }
      
      else if(menu3_choice == 3) {
        std::cout << "\n========== EXITING MENU - 3 ==========\n";
        break;
      }
      
      else {
        std::cout << "Invalid choice\n";
      }
    }  
   }
   
   else if(menu_choice == 4) {
     std::cout << "\n========== EXITING PROGRAM ==========\n\n";
     break;
   }
   
   else {
     std::cout << "Invalid choice\n";
   }
    
  }
  
  return 0;
}