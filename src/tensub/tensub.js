import puppeteer from 'puppeteer';

(async () => {

    // Launch the browser and open a new blank page
    const browser = await puppeteer.launch({ headless: false , browser : "firefox"});
    const page = await browser.newPage();
    await page.setViewport({width: 1080, height: 1024});
    //await page.setRequestInterception(true);

    // page.on('request', (req) => {
    //     if(req.resourceType() === 'image'){
    //         req.abort();
    //     }
    //     else {
    //         req.continue();
    //     }
    // });

    await page.goto('https://loisirs.montreal.ca');
   
    await page.waitForSelector('#u2000_btnSignIn', {
        visible: true,
        timeout: 20000, // Temps d'attente en millisecondes
      });

    await Promise.all([
        page.waitForNavigation({ waitUntil: 'load' }),
        page.click('#u2000_btnSignIn')
      ]);


    await page.type('#signInName', "");
    await page.type('#password', "");

    await page.waitForSelector('#next',{ visible: true , timeout: 5000});
    await page.click('#next'); 

    await page.waitForSelector('#u2000_btnProfileMenu',{ visible: true , timeout: 10000});

      var today = new Date();
      var starttime = new Date();
      var endtime = new Date();

      const dayOfWeek = today.getDay(); // Jour actuel (0 = dimanche, 1 = lundi, ..., 6 = samedi)
      const daysUntilSaturday = (6 - dayOfWeek + 7) % 7 || 7; // Jours restants jusqu'à samedi
      const nextSaturday = new Date(today);
      nextSaturday.setDate(today.getDate() + daysUntilSaturday); // Ajouter les jours restants

      const formatDate = (date) => {
        return date.toISOString(); // Enlever le Z et ajouter le fuseau horaire
      };

      console.log(formatDate(nextSaturday));
      starttime.setHours(9, 15, 0); // Définir l'heure, les minutes, les secondes et les millisecondes
      endtime.setHours(10, 15, 0);
      console.log(formatDate(starttime));
      console.log(formatDate(endtime));

      var terrain = "Terrain 3";

      await page.goto('https://loisirs.montreal.ca/IC3/#/U6510/search/?searchParam={"filter": {"isCollapsed":false,"value": {"startTime" : "'+formatDate(starttime)+'", "endTime" : "'+formatDate(endtime)+'",  "dates" :["'+formatDate(nextSaturday)+'"]}}, "search":"'+terrain+'", "sortable":{"isOrderAsc":true,"column":"facility.name"}}');
    
     await page.waitForSelector('#u6510_btnButtonReservation0',{ visible: true , timeout: 10000});
     await page.click('#u6510_btnButtonReservation0')
     

     await page.waitForSelector('#u3600_btnSelect0',{ visible: true , timeout: 5000});
     await page.click('#u3600_btnSelect0');

     const [response] = await Promise.all([
        page.waitForNavigation(),
        page.click('#u3600_btnCheckout0'),
      ]);
      
     


    //  const Select = page.waitForNavigation();
    //  await page.click('#u3600_btnSelect0')
    //  await page.click('#u3600_btnCheckout0')
    //  await Select;
    
    //  await Promise.all([
    //       page.click('#u3600_btnSelect0'),
    //       page.click('u3600_btnCheckout0')
    //    ]);
    //    await page.waitForSelector('#u3600_btnSelect0', {visible: true})       

     



    //await browser.close();
})();

