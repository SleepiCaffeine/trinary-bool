# trinary-bool
I was bored one night while making blackjack, and decided to make this monstrocity...
This is a custom data type that supports basically everything a regular boolean does, however boolean arithmetic with the standard binary booleans will result in issues.

## How to use it
`tbool` uses 1 as *true*, 0 as *neutral*, and -1 as *false*.

Creating `tbool`s:
```
#include "tbool.h"
int main() {

  // All of these are valid
  tb::tbool neutral = tb::NEUTRAL;        // 0
  tb::tbool _false  = false;              // -1
  tb::tbool* _true  = new tb::tbool(1);   // 1
  
  /* (...) */
}
```

Comparing `tbool`s:
```
if (neutral)
  // will run, as neutral is considered truthy
  
if (_true)
  // Obviously
  
if (_false)
  // You get the idea
  
if (_true + _false == neutral)
  // Will run, since they both evaluate to 0
  
if (true + false == neutral)
  // Will not run, as it will evaluate to 1 == 0
  
if (false == _neutral)
  // Will not run, despite evaluating to 0
  
if (_true * _false == _false)
  // I don't know what you would use this for, but pop off
  
if (neutral >= false)
  // Will evaluate, since neutral is truthy
  
if (_false + _true == (neutral + _true * _false + neutral) / _true + _true)
  // This actually works and will run code below
```

## Known Bugs
- Sometimes comparisons fail due to not being positioned on the correct side of the comparison. I am working on this, and there might be a fix in the near-ish future?
- On some comparisons, ambigious comparison warnings may appear. I have no clue how to fix that, but I'm trying.

## Authors
me, and my trusty coffee mug.

## Issues and Pull requests
yes please, I want to know what's wrong with this "thing" I've created.

## License
This project is protected under the MIT license.
