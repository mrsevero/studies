def split_and_join(line):
    line = line.split(" ")
    
    line = line = "-".join(line)

    return line
    
        
    return line    
if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
