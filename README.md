# ESP32-my_string
Library for ESP32 - String manipulation library

## Description
Provides functions related to character strings.

## Functions
* [trim](#trim)
* [ltrim](#ltrim)
* [rtrim](#rtrim)

## Reference
### trim
* Declaration  
```c
char *trim(char *src, const char **blank_string_list);  
```

* Description  
Returns a string with leading and trailing blanks removed.  
* Argument  

|Argument|Description|  
|:--|:--|  
|src|String to delete leading and trailing whitespace.<br>Strings are subject to change.|  
|blank_string_list|List of strings to be removed as blank characters.<br>Multibyte characters can also be specified.<br>You need to place a NULL pointer at the end of the list.|  

* Return value  
String with leading and trailing white space removed.  
NULL if the argument contains a NULL pointer.  

### ltrim
* Declaration  
```c
char *ltrim(char *src, const char **blank_string_list);  
```

* Description  
Returns the string with leading blanks removed.  
* Argument  

|Argument|Description|  
|:--|:--|  
|src|String to delete trailing white space characters.|  
|blank_string_list|List of strings to be removed as blank characters.<br>Multibyte characters can also be specified.<br>You need to place a NULL pointer at the end of the list.|  

* Return value  
String with leading blanks removed.  
NULL if the argument contains a NULL pointer.  

### rtrim
* Declaration  
```c
char *rtrim(char *src, const char **blank_string_list);  
```

* Description  
Returns a string with trailing blanks removed.  
* Argument  

|Argument|Description|  
|:--|:--|  
|src|String to delete leading white space character.<br>Strings are subject to change.|  
|blank_string_list|List of strings to be removed as blank characters.<br>Multibyte characters can also be specified.<br>You need to place a NULL pointer at the end of the list.|  

* Return value  
String with trailing blanks removed.  
NULL if the argument contains a NULL pointer.  
