#include <malloc.h>
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"

int shouldFail = 1;

void doThings() {
  // ErrorObject *err;
  
  // Try {
    doSomething();
  // } Catch(err) {
    // printf("Error: %s\n", err->errorMsg);
    // freeError(err);
  // }
}

int doSomething(){
  if(shouldFail){
    throwError("Hey! Something is really wrong here.", \
               ERR_DUNNO_WHAT_HAPPEN);
  }
  return 1;
}
/**
 * Add two numbers. The first number must be negative.
 * The second number must be positive no more than 50
 */
int specialAdd(int negVal, int posVal){
  int result = negVal + posVal;
  ErrorObject *err = malloc(sizeof(ErrorObject));
  if(negVal >= 0)
    throwError("First number is not negative", ERR_NUMBER_NOT_NEGATIVE);
  else if(posVal < 0)
    throwError("Second number is not positive", ERR_NUMBER_NOT_POSITIVE);
  else if(posVal >= 50)
    throwError("Second number is more than 50", ERR_NUMBER_TOO_LARGE);
  return result;
}