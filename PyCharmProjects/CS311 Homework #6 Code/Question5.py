def names_starting_with_X_or_Y(names):
    for name in names:
        if name.startswith('X') or name.startswith('Y'):
            print(name)

# Example usage
names = ['Catherine', 'Xander', 'Jorge', 'Albert', 'Yolanda', 'Phu', 'Xavier', 'Monika', 'Yasmin']
names_starting_with_X_or_Y(names)
