import React, { useState, useEffect, useRef, useCallback } from "react";
import footerLinks from "./footerLinks"; // Assume this file contains the footer links data
import { FaFacebook, FaInstagram, FaTwitter, FaYoutube } from "react-icons/fa"; // Using react-icons for social media icons

const Footer = () => {
  const [dots, setDots] = useState([]);
  const canvasRef = useRef(null);
  const footerRef = useRef(null);

  const arrayColors = ["#A00000", "#E50914", "#Ff0000", "#fff", "#303030"];

  const initializeDots = useCallback(() => {
    if (!footerRef.current) return;
    const { offsetWidth, offsetHeight } = footerRef.current;
    const newDots = Array.from({ length: 60 }, () => ({
      x: Math.floor(Math.random() * offsetWidth),
      y: Math.floor(Math.random() * offsetHeight),
      size: Math.random() * 3 + 5,
      color: arrayColors[Math.floor(Math.random() * arrayColors.length)],
    }));
    setDots(newDots);
  }, []);

  useEffect(() => {
    initializeDots();
    window.addEventListener("resize", initializeDots);
    return () => window.removeEventListener("resize", initializeDots);
  }, [initializeDots]);

  useEffect(() => {
    const canvas = canvasRef.current;
    const ctx = canvas.getContext("2d");
    const footer = footerRef.current;

    const drawDots = () => {
      if (!canvas || !footer) return;
      canvas.width = footer.offsetWidth;
      canvas.height = footer.offsetHeight;
      ctx.clearRect(0, 0, canvas.width, canvas.height);
      dots.forEach((dot) => {
        ctx.fillStyle = dot.color;
        ctx.beginPath();
        ctx.arc(dot.x, dot.y, dot.size, 0, Math.PI * 2);
        ctx.fill();
      });
    };

    const handleMouseMove = (event) => {
      if (!canvas || !footer) return;
      drawDots();
      const rect = footer.getBoundingClientRect();
      const mouse = {
        x: event.clientX - rect.left,
        y: event.clientY - rect.top,
      };
      dots.forEach((dot) => {
        const distance = Math.sqrt((mouse.x - dot.x) ** 2 + (mouse.y - dot.y) ** 2);
        if (distance < 200) {
          ctx.strokeStyle = dot.color;
          ctx.lineWidth = 1;
          ctx.beginPath();
          ctx.moveTo(dot.x, dot.y);
          ctx.lineTo(mouse.x, mouse.y);
          ctx.stroke();
        }
      });
    };

    drawDots();
    footer.addEventListener("mousemove", handleMouseMove);
    return () => footer.removeEventListener("mousemove", handleMouseMove);
  }, [dots]);

  return (
    <footer ref={footerRef} className="relative bg-black text-red-600 py-10 overflow-hidden">
      <div className="max-w-screen-xl mx-auto flex flex-col items-center z-10">
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-5 gap-8 w-full">
          {footerLinks.map((column, index) => (
            <div key={index} className="footer-column">
              <h3 className="text-white mb-2">{column.title} &#8595;</h3>
              <ul>
                {column.links.map((link, idx) => (
                  <li key={idx} className="my-2 transform transition duration-300">
                    {typeof link === "string" ? (
                      <a href={`#${link.toLowerCase().replace(/\s+/g, '-')}`} className="text-gray-500 hover:text-red-500">
                        &#8594; {link}
                      </a>
                    ) : (
                      <a href={link.url} target="_blank" rel="noopener noreferrer">
                        <img src={link.imgSrc} alt={link.alt} className="h-12 w-24 mx-auto" />
                      </a>
                    )}
                  </li>
                ))}
              </ul>
            </div>
          ))}
        </div>
        <div className="footer-social my-5">
          <h3 className="text-white mb-2">Social Media Links &#8595;</h3>
          <div className="flex space-x-4">
            <a href="#facebook" aria-label="Facebook" className="text-gray-500 hover:text-red-500"><FaFacebook size={24} /></a>
            <a href="#instagram" aria-label="Instagram" className="text-gray-500 hover:text-red-500"><FaInstagram size={24} /></a>
            <a href="#twitter" aria-label="Twitter" className="text-gray-500 hover:text-red-500"><FaTwitter size={24} /></a>
            <a href="#youtube" aria-label="YouTube" className="text-gray-500 hover:text-red-500"><FaYoutube size={24} /></a>
          </div>
        </div>
        <div className="footer-logo mt-5">
          <img
            src="/images/netflix-logo.gif" // Assume local optimized image
            alt="Netflix Logo"
            className="w-32 mx-auto animate-float"
          />
        </div>
      </div>
      <canvas
        ref={canvasRef}
        className="absolute top-0 left-0 w-full h-full pointer-events-none"
      />
      <div className="bg-gray-500 w-full overflow-hidden mt-5">
        <div className="flex justify-around animate-move">
          <p className="text-black font-semibold">&copy; All Rights Are Reserved !</p>
          <p className="text-red-500 font-semibold">&#x40; Sheriyans Coding School</p>
          <p className="text-black font-semibold">&#9758; API Alchemists</p>
          <p className="text-red-500 font-semibold">&#8482; ReImagine Round2</p>
          <p className="text-black font-semibold">#Round2Submission</p>
        </div>
      </div>
    </footer>
  );
};

export default Footer;
