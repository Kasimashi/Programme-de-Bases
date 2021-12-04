#ifndef COMMON_H_
#define COMMON_H_


/* Handle Error : callback for error */
void err_n_die(const char *fmt, ...);

char *bin2hex(const unsigned char *input, size_t len);


#endif /* COMMON_H_ */
