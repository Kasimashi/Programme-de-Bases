# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Client Server

# Tool invocations
Client: 
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "Client-HTTP" src/client-HTTP.c src/common.c -Iinclude/
	@echo 'Finished building target: $@'
	@echo ' '
	
# Tool invocations
Server:
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "Server-HTTP" src/server-HTTP.c src/common.c -Iinclude/
	@echo 'Finished building target: $@'
	@echo ' '
