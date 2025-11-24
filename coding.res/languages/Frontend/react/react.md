# React

[React App Reference](https://github.com/t20e/trading-app/tree/main/client)

Prerequisite:

1. `npm` package manager

### Create A React App

```zsh
npx create-react-app app_name
cd app_name

npm install react-router-dom

# Start the react developer server
npm start
```

- 🚨NOTE in developer mode, certain effects, including those in useEffect with an empty dependency will run twice, this is to catch any side effects.

    ```js
    // Example:
    useEffect(() => {
        console.log("Runs twice");
    }, []);
    ```

### How To Make A Build For Production

```shell
cd react_app; # client
npm i serve; # Install the serve package for testing the build locally.
npm run build; # Create the build

# Run locally for testing the build.
npx serve -s build; 
```


### Other Packages

```zsh
npm install axios
```
