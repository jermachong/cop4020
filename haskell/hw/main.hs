{--
    Jeremy Achong
    5124781
    Implementing pi approximations in Haskell
    Link: https://www.tutorialspoint.com/compilers/online-haskell-compiler.htm
--}

-- short pi function
shortpi::Double -- void function to give simplepi approximation
shortpi = 4*(4 * atan( 1 / 5 ) - atan(1/239))


-- 4 times the sum of the equation using list comprehension from 1 to 200
-- takes in an int as the upperbound of summation and returns approximation in form of a Double
simplepi::Int -> Double
simplepi n = -- fromIntegral is a conversion function to safely convert int to any other numerical type, like double
    4 * sum [fromIntegral ((-1)^(k+1)) / fromIntegral (2*k-1) | k<-[1..n]]

-- square root of 8 times the sum of 1 / 2*(k-1)^2
-- similar to simplepi, takes int as upper limit and returns approximation 
wellspi::Int->Double
wellspi n = 
-- uses sqrt from standard library
    sqrt(8 * sum[fromIntegral 1 / (fromIntegral (2*k-1) * fromIntegral (2*k-1)) | k<-[1..n]])

-- takes in int as upper limit and returns approximation using euler formula
eulerpi::Int->Double
eulerpi n = 
    sqrt(6*sum[fromIntegral 1 / fromIntegral (k^2)| k<-[1..n]])


-- two functions to do wallis sequence since there is no Pi operator
-- n is the limit of iterations, 1 is the first iteration of k, and 1.0 is the start of the product
wallis::Int->Double
wallis n = wallishelp n 1 1.0

-- recursive function that multiplies the product by wallis formula until k has reached 200
wallishelp::Int->Int->Double->Double
wallishelp n k product =
    if k > n then -- base case, finish calculation by multiplying by 2
        product * 2
    else -- everytime the wallis formula is calulated, the product is updated by multiplying itself by the new result
        wallishelp n (k+1) (product * (fromIntegral (2*k) / fromIntegral (2*k-1)) * (fromIntegral (2*k) / fromIntegral (2*k+1)))

main::IO()
main = do
    let n = 200
    putStrLn("Short pi: \n" ++ show(shortpi)) -- single calculation, no n needed
    putStrLn ("Simple pi: \n" ++ show(simplepi n))
    putStrLn("Wells pi: \n" ++ show(wellspi n)) -- most precise for 200 iterations
    putStrLn("Euler pi: \n" ++show(eulerpi n))
    putStrLn("Wallis pi: \n" ++ show(wallis n)) 
