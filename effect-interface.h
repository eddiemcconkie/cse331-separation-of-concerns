#pragma once



class EffectInterface : public DrawableObjectInterface
{
public:
   virtual void render() const = 0;

};

class FragmentInterface : public EffectInterface {
   // draw it
   void render() const;
};

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class StreekInterface : public EffectInterface
{

public:
    // draw it
    void render() const;
    
    
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class ExhaustInterface : public EffectInterface
{
public:

    // draw it
    void render() const;
    
};