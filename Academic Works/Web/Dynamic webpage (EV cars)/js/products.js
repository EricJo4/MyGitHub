/**
 * products.js
 *
 * The store's products are defined as an Array of product Objects.
 * Each product Object includes the following properties:
 *
 *  - id: String, a unique product identifier (e.g., "P1", "P2")
 *  - title: String, a short name for the product (e.g., "Gingerbread Cookie")
 *  - description: String, a description of the product
 *  - price: Number, the unit price of the item in whole cents (e.g., 100 = $1.00, 5379 = $53.79)
 *  - discontinued: Boolean, whether or not the product has been discontinued
 *  - categories: Array, the category id or ids to which this product belongs (e.g., ["c1"] or ["c1", "c2"])
 */

window.products = [
  {
    id: "TSLA-16674",
    title: "Tesla Model 3",
    description:
      "A minimal interior aesthetic—with all controls accessible on the central 15-inch touchscreen and the steering wheel. The forward-designed instrument panel provides even more legroom in the front, for a spacious passenger cabin. The premium center console is modern and efficient, with plenty of covered storage and charging for two smartphones. The back seat is very comfortable—with maximum legroom and beautiful views through the all-glass roof.",
    price: 5100000,
    discontinued: false,
    categories: ["RODM-TESLA"],
  },

  {
    id: "TSLA-16675",
    title: "Tesla Model Y",
    description:
      "Model Y is fully electric, so you never need to visit a gas station again. If you charge overnight at home, you can wake up to a full battery every morning. And when you're on the road, it's easy to plug in along the way—at any public station or with the Tesla charging network. We currently have over 45,000 Superchargers worldwide, with six new locations opening every week.",
    price: 5999000,
    discontinued: false,
    categories: ["RODM-TESLA"],
  },

  {
    id: "TSLA-26674",
    title: "Tesla Model X",
    description:
      "With ample storage and 2,267 kg of towing capacity, Model X is built for maximum utility. Front doors open and close automatically, Falcon Wing rear doors allow for easier loading and a trailer hitch comes standard, so you can bring your gear with you wherever you go.",
    price: 13599000,
    discontinued: false,
    categories: ["RODM-TESLA"],
  },

  {
    id: "TSLA-26675",
    title: "Tesla Model S",
    description:
      "With up to 652 kilometers of estimated range and access to the world's largest and most powerful fast charging network, you'll spend less time plugged in and more time on the road.",
    price: 12199000,
    discontinued: false,
    categories: ["RODM-TESLA"],
  },

  {
    id: "TSLA-36674",
    title: "Tesla Cyber Truck",
    description:
      "Cybertruck is built with an exterior shell made for ultimate durability and passenger protection. Starting with a nearly impenetrable exoskeleton, every component is designed for superior strength and endurance, from Ultra-Hard 30X Cold-Rolled stainless-steel structural skin to Tesla armor glass.",
    price: 5000000,
    discontinued: false,
    categories: ["RODM-TESLA"],
  },

  {
    id: "PORSCHE-18464",
    title: "Porsche Tycan",
    description:
      "The new Taycan GTS and Taycan GTS Sport Turismo charge the Porsche electric driving experience with even more intense emotion.",
    price: 18103000,
    discontinued: false,
    categories: ["RODM-PORSCHE"],
  },

  {
    id: "FORD-16481",
    title: "Ford F-150 Lightning",
    description:
      "The Ford F-Series has been Canada's best-selling truck for 56 years88. Now it's charging into the future with the electric-powered F-150® Lightning®.",
    price: 6900000,
    discontinued: false,
    categories: ["RODM-FORD"],
  },

  {
    id: "FORD-13446",
    title: "Ford Mustang Mach-E",
    description:
      "The all-electric Mustang Mach-E® SUV gives you 0-100 thrills and expansive range.",
    price: 5699500,
    discontinued: false,
    categories: ["RODM-FORD"],
  },

  {
    id: "FORD-13447",
    title: "Ford Mustang Mach-E GT",
    description:
      "The all-electric Mustang Mach-E® SUV gives you 0-100 thrills and expansive range.",
    price: 8299500,
    discontinued: false,
    categories: ["RODM-FORD"],
  },

  {
    id: "GM-15964",
    title: "GM Bolt EV",
    description:
      "The award-winning Bolt EV is an all-electric crossover that offers up to estimated 417 kilometers of pure electric range on a full charge102. Built with the utility of a crossover from the inside out, this vehicle has plenty of head - and legroom, and with folding rear seats, it has up to 1,603 liters of maximum cargo space.",
    price: 3990000,
    discontinued: false,
    categories: ["RODM-GM"],
  },

  {
    id: "BENZ-94651",
    title: "EQB 350 4MATIC",
    description:
      "The all-electric, all-wheel-drive EQB 350 4MATIC packs big space, style and smart ideas into a compact SUV. With seating for up to seven, a virtual voice assistant and MB Navigation with Electric Intelligence, the EQB is a flexible, forward-thinking and fun family-sized SUV.",
    price: 20500000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94652",
    title: "EQE 350 4MATIC",
    description:
      "The EQE electrifies the essence of Mercedes-Benz values. Leadership in user-friendly technology and earth-friendlier power. Driving confidence and passenger satisfaction. And the seamless confluence of craftsmanship and innovation that make the iconic grille Star shine.",
    price: 18050000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94653",
    title: "EQE 500 4MATIC",
    description:
      "The EQE electrifies the essence of Mercedes-Benz values. Leadership in user-friendly technology and earth-friendlier power. Driver rewards with refinement for all aboard. And the seamless confluence of craftsmanship and innovation that make the iconic grille Star shine.",
    price: 19550000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94654",
    title: "AMG EQE 4MATIC+",
    description:
      "The Mercedes-AMG EQE advances Driving Performance in to an electrifying new era. An abundance of all-electric torque is transmitted to all four wheels much in the way it drives your emotions: swiftly, surely and sensationally. It's the AMG tradition, re-energized and reborn.",
    price: 20550000,
    discontinued: true,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94655",
    title: "EQS 450 4MATIC",
    description:
      "The EQS SUV brings the luxury SUV into a bold new era. All-electric performance. All-wheel capability. Elegance in a modern form. Spacious, sumptuous and thoughtfully futuristic inside, with three roomy rows. And the depth of character that defines a Mercedes SUV.",
    price: 30550000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94656",
    title: "EQS 450 4MATIC",
    description:
      "The EQS SUV brings the luxury SUV into a bold new era. All-electric performance. All-wheel capability. Elegance in a modern form. Spacious, sumptuous and thoughtfully futuristic inside, with three roomy rows. And the depth of character that defines a Mercedes SUV.",
    price: 30550000,
    discontinued: true,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94657",
    title: "EQS 580 4MATIC",
    description:
      "The EQS SUV brings the luxury SUV into a breathtakingly new era. All-electric performance. All-wheel capability. Futuristic elegance inside and out, with a user-friendly tech and family-friendly 3-row seating. And the depth of character that defines a Mercedes SUV.",
    price: 32550000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "BENZ-94658",
    title: "AMG EQS 4MATIC+",
    description:
      "The Mercedes-AMG EQS launches the future of all-electric Driving Performance. It can rush a seamless torrent of AMG torque to all four of its wheels, and a rush of endorphins to its driver, all in the AMG tradition. And all like never before.",
    price: 33550000,
    discontinued: false,
    categories: ["RODM-BENZ"],
  },

  {
    id: "VOLKS-46544",
    title: "Volkswagen ID.4",
    description:
      "The ID.4 is packed with lots of exciting additions, like a new battery, interior décor and seating options, available statement package and more.",
    price: 4917500,
    discontinued: false,
    categories: ["RODM-VOLKS"],
  },

  {
    id: "VOLKS-46545",
    title: "Volkswagen ID.7",
    description:
      "Electric feels good in our first-ever all-electric sedan. Arriving in Canada in 2024.",
    price: 5917500,
    discontinued: false,
    categories: ["RODM-VOLKS"],
  },
];
