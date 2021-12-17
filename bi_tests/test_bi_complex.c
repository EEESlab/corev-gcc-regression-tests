#include <stdio.h>
#include <stddef.h>

float input[500] = {35.6}; 
char features[500] = {5};
float threshold[500] = {-70.6}; 
unsigned short int children[500] = {350};

unsigned short int rf2arr(

    float *input, 
    char *features,
    float *threshold,
    unsigned short int *children

)
{
    unsigned int input_addr = (unsigned int) &input[0];
    unsigned int threshold_addr = (unsigned int) &threshold[0];
    unsigned int features_addr = (unsigned int) &features[0];
    unsigned int children_addr = (unsigned int) &children[0];

    int current_feature = features[0];
    unsigned int current_node = 0;

    do{
        if (*((float *)(input_addr + current_feature)) <= *((float *)(threshold_addr + current_node)))
        {
            current_node = *((unsigned short int *)(children_addr + current_node));
        }
        else
        {
            current_node = *((unsigned short int *)(children_addr + (current_node + 2)));
        }
        current_feature = *((char *)(features_addr + (current_node >> 2)));
    
    } while(current_feature != (-8));


    return (unsigned short int) (*((unsigned int *)(children_addr + current_node)) >> 18);

}

int main()
{
  unsigned short int res = 0;
  res = rf2arr(input, features, threshold, children);
  printf("res=%d\n", res);

  return 0;
}
