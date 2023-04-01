#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void getBeverage(std::string& _return, const BeverageType::type type) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"
void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type type) {
    std::vector<std::string> beverageType_hot = {"cappuccino", "latte", "espresso"};
    std::vector<std::string> beverageType_cold = {"lemonade", "ice tea", "soda"};

    std::vector<std::string> selectBeverages;
    if (type == BeverageType::type::HOT) {
        selectBeverages = beverageType_hot;
    } else {
        selectBeverages = beverageType_cold;
    }

    //Randoml function to select the beverages
    int random_index = rand() % selectBeverages.size();
    _return = selectBeverages[random_index];
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

