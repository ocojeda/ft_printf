#include "ft_printf.h"

static void    reset_options(t_type *temp)
{
    temp->plus = 0;
    temp->negative = 0;
    temp->hash_tag =0;
    temp->pres_left = 0;
    temp->pres_right = 0;
    temp->no_pres_left = 0;
    temp->no_pres_right = 0;
    temp->spaces = 0;
    temp->currency = 0;
    temp->nopoint = 0;
    temp->cast = 0;
    temp->cero = 0;
}
void    reset_type(t_type *temp)
{
    temp->type = 0;
    temp->unbr = 0;
    temp->lunbr = 0;
    temp->lnbr = 0;
    temp->pointer = 0;
    temp->fnumber = 0;
    temp->str = NULL;
    temp->c = 0;
    temp->wstr = NULL;
    temp->wc = 0;
    temp->hexa = 0;
    ft_bzero(temp->str1, 1000);
    reset_options(temp);
}
void    u_option_parser(t_type *temp, va_list args)
{
   /*
   * function tres facile a reduire, a verifier avec 42fchecker
   */
   if(temp->cast == HH_CAST)
   {
      temp->type = INTI;
      temp->number = va_arg(args, long long);
      while(temp->number > 256)
        temp->number -= 256;
            temp->cast = 0;
    }
    else if(temp->cast == H_CAST)
    {
        temp->type = INTI;
        temp->number = va_arg(args, long long);
        while(temp->number > 65535)
            temp->number -= 65535;
        temp->cast = 0;
    } 
    else if(temp->cast == LONG_LONG || temp->cast == LONG || temp->cast == J_CAST || temp->cast == Z_CAST)
    {
        temp->type = INTLU;
        temp->lunbr = va_arg(args, long unsigned int);        
    }
    else
    {
        temp->type = INTI;
        temp->number = va_arg(args, long long);
        temp->cast = LONG_LONG;
        if(temp->number < 0)
            temp->number *= -1;
        temp->spaces = 0;
    }
}
int      cdiop_cases(t_type *temp, char *str, int i, va_list args)
{
    if (str[i] == 'c' && !temp->type)
    {
        temp->type = CHAR;
        if(temp->cast == LONG_LONG || temp->cast == LONG)
        {
             temp->type = WCHAR;
             temp->wc = va_arg(args, wchar_t);
        }
        else
            temp->c = va_arg(args, int);
    }
    if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
    {
        temp->type = INTI;
        temp->number = va_arg(args, long long);
    }

    if (str[i] == 'p' && !temp->type)
    {
        temp->type = POINTER_ADRESSE;
        temp->pointer = va_arg(args, unsigned long);
    }
    if (str[i] == 'o' && !temp->type)
    {
        temp->type = OCTAL;
        if(temp->cast == LONG_LONG || temp->cast == LONG)
            temp->octal = va_arg(args, unsigned long long);
        else if(temp->cast == J_CAST)
            temp->octal = va_arg(args, uintmax_t);
        else
            temp->octal = va_arg(args, unsigned int);
    }
    return (i+1);
}